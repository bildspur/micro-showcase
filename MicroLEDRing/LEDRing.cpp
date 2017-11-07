#include "LEDRing.h"
#include <FastLED.h>

LEDRing::LEDRing(int count) {
  leds = new CRGB[count];
}

void LEDRing::light(CRGB color) {
  for ( int i = 0; i < count; i++) {
    leds[i] = color;
  }
}

void LEDRing::clear() {
  FastLED.clear();
}

void LEDRing::show() {
  FastLED.show();
}

