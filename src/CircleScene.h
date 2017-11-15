#ifndef CircleScene_h
#define CircleScene_h

#include "LEDRing.h"
#include "LightScene.h"
#include "MicroUtils.h"

class CircleScene : public LightScene {
private:
    CHSV baseColor = fromHSV(180, 100, 100);
    CHSV highlightColor = fromHSV(180, 20, 50);

    double startIndex = 0.4;
    double sizeIndex = 0.1;
    double speed = 0.02;

    CRGBPalette16 palette;
    TBlendType blending = LINEARBLEND;

    void loopRing(LEDRingPtr ring);

public:
    CircleScene();

    void setup(LEDRingPtr *rings) override;

    void loop() override;
};

#endif
