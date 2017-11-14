#ifndef LightScene_h
#define LightScene_h

#include "LEDRing.h"
#include "MicroUtils.h"

class LightScene {
private:
public:
  LEDRingPtr *rings;

  LightScene();
  virtual void setup(LEDRingPtr *rings);
  virtual void loop();
};

#endif
