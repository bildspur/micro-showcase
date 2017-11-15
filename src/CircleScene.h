#ifndef CircleScene_h
#define CircleScene_h

#include "LEDRing.h"
#include "LightScene.h"
#include "MicroUtils.h"
#include "DistanceSensorArray.h"

class CircleScene : public LightScene {
private:
    CHSV baseColor = fromHSV(180, 100, 100);
    CHSV highlightColor = fromHSV(180, 20, 50);

    double startIndex = 0.4;
    double sizeIndex = 0.1;
    double speed = 0.02;

    CRGBPalette16 palette;
    CRGBPalette16 activePalette;
    TBlendType blending = LINEARBLEND;

    void loopRing(LEDRingPtr ring);

    DistanceSensorArray *sensorArray;

public:
    CircleScene();

    void setup(LEDRingPtr *rings, DistanceSensorArray *sensorArray);

    void loop() override;
};

#endif
