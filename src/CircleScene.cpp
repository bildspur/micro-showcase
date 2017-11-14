#include "CircleScene.h"

CircleScene::CircleScene() {
  // 'black out' all 16 palette entries...
  fill_solid(palette, 16, CRGB::White);
  // and set every fourth one to white.

  for (int i = 0; i < 12; i++) {
    palette[i] = CRGB::Cyan;
  }
};

void CircleScene::setup(LEDRingPtr *rings) { LightScene::setup(rings); };

void CircleScene::loop() {
  for (uint8_t i = 0; i < sizeof(rings); i++) {
    loopRing(rings[i]);
  }
};

void CircleScene::loopRing(LEDRingPtr ring) {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;

  uint8_t colorIndex = startIndex;

  uint8_t brightness = 255;

  for (int i = 0; i < ring->length; i++) {
    ring->leds[i] = ColorFromPalette(palette, colorIndex, brightness, blending);
    colorIndex += 3;
  }

  // set base color (reset)
  // ring->all(baseColor);

  // show white part
  /*
  ring->set(highlightColor, startIndex, startIndex + sizeIndex);

  startIndex += speed;
  if (startIndex > 1.0)
    startIndex = 0.0;
  */

  /*
  Serial.print("Startindex: ");
  Serial.println(startIndex);
  */
};
