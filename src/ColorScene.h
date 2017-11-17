//
// Created by Florian on 17.11.17.
//

#ifndef MICRO_SHOWCASE_COLORSCENE_H
#define MICRO_SHOWCASE_COLORSCENE_H


#include "LightScene.h"
#include "Timer.h"

#define PALETTE_TIME (1000 * 60 * 5)

class ColorScene : public LightScene {
private:
    CRGBPalette16 currentPalette;
    TBlendType currentBlending;

    CRGBPalette16 microPalette;

    uint8_t startIndex = 0;
    uint8_t brightness = 255;

    uint8_t paletteIndex = 0;

    Timer timer = Timer(static_cast<unsigned long>(PALETTE_TIME));

public:
    ColorScene();

    void setup(LEDRingPtr *rings) override;

    void loop() override;

    void changePalette();
};


#endif //MICRO_SHOWCASE_COLORSCENE_H
