#ifndef LightScene_h
#define LightScene_h

#include "LEDRing.h"

class LightScene {
private:
  LEDRing *rings;

public:
  LightScene();
  virtual void setup(LEDRing *rings);
  virtual void loop();
};

#endif
