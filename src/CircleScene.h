#ifndef CircleScene_h
#define CircleScene_h

#include "LEDRing.h"
#include "LightScene.h"

class CircleScene : public LightScene {
private:
  CHSV baseColor;

public:
  CircleScene();
  virtual void setup(LEDRingPtr *rings);
  virtual void loop();
};

#endif
