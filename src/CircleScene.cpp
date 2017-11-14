#include "CircleScene.h"
#include "MicroUtils.h"

CircleScene::CircleScene() { baseColor = fromHSV(180, 100, 100); };
void CircleScene::setup(LEDRingPtr *rings) { LightScene::setup(rings); };
void CircleScene::loop() {
  for (uint8_t i = 0; i < sizeof(rings); i++) {
    LEDRingPtr ring = rings[i];
    ring->all(baseColor);
  }
};
