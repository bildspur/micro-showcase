//
// Created by Florian on 17.11.17.
//

#include "ColorScene.h"

ColorScene::ColorScene() {

}

void ColorScene::setup(LEDRingPtr *rings) {
    LightScene::setup(rings);

    // setup microPalette
    fill_solid(microPalette, 16, CRGB::Gray);
    for (int i = 0; i < 12; i++) {
        microPalette[i] = CRGB::Cyan;
    }

    changePalette();
}

void ColorScene::loop() {
    LightScene::loop();

    if(timer.elapsed())
    {
        // change palette
        paletteIndex = (paletteIndex + 1) % 2;
        changePalette();
    }

    startIndex = (startIndex + 1) % 14400; /* motion speed */

    // set rings
    uint8_t colorIndex = startIndex;
    for (uint8_t i = 0; i < sizeof(rings) + 1; i++) {
        for( int j = 0; j < rings[i]->length; j++) {
            rings[i]->leds[j] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
            colorIndex += 3;
        }
    }
}

void ColorScene::changePalette() {
    currentBlending = LINEARBLEND;

    if(paletteIndex == 0) {currentPalette = RainbowColors_p;}
    if(paletteIndex == 1) {currentPalette = microPalette;}
}
