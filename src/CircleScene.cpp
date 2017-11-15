#include "CircleScene.h"

CircleScene::CircleScene() {
    // 'black out' all 16 palette entries...
    fill_solid(palette, 16, CRGB::Gray);

    fill_solid(activePalette, 16, CRGB::Gray);

    // and set every fourth one to white.
    for (int i = 0; i < 12; i++) {
        palette[i] = CRGB::Cyan;
        activePalette[i] = CRGB::Magenta;
    }
};

void CircleScene::setup(LEDRingPtr *rings,DistanceSensorArray *sensorArray) {
    LightScene::setup(rings);
    this->sensorArray = sensorArray;
};

void CircleScene::loop() {
    for (uint8_t i = 0; i < sizeof(rings) + 1; i++) {
        loopRing(i, rings[i]);
    }
};

void CircleScene::loopRing(uint8_t id, LEDRingPtr ring) {
    static uint8_t startIndex = 0;
    startIndex = (startIndex + 1) % 14400;

    uint8_t colorIndex = startIndex;

    uint8_t brightness = 255;

    bool sensorDetected = false;

    // check sensors
    if(id == 0 && sensorArray->results[0] < INTERACTION_DISTANCE)
        sensorDetected = true;

    if(id == 0 && sensorArray->results[1] < INTERACTION_DISTANCE)
        sensorDetected = true;

    if(id == 1 && sensorArray->results[2] < INTERACTION_DISTANCE)
        sensorDetected = true;

    if(id == 2 && sensorArray->results[3] < INTERACTION_DISTANCE)
        sensorDetected = true;

    if(id == 2 && sensorArray->results[4] < INTERACTION_DISTANCE)
        sensorDetected = true;

    for (int i = 0; i < ring->length; i++) {
        if (sensorDetected)
            ring->leds[i] = ColorFromPalette(activePalette, colorIndex, brightness, blending);
        else
            ring->leds[i] = ColorFromPalette(palette, colorIndex, brightness, blending);
        colorIndex += 3;
    }

    /*
    // set base color (reset)
    ring->all(baseColor);

    // show white part

    ring->set(highlightColor, startIndex, startIndex + sizeIndex);

    startIndex += speed;
    if (startIndex + sizeIndex > 1.0)
      startIndex = 0.0;

    Serial.print("Startindex: ");
    Serial.println(startIndex);
     */
};
