#include "LEDRing.h"
#include <FastLED.h>

LEDRing::LEDRing(int count) {
  leds = new CRGB[count];

  // clear arrays
  for (int i = 0; i < count;  ++i)
    leds[i] = CRGB::Black;
}

void LEDRing::all(CRGB color) {
  for ( int i = 0; i < count; i++) {
    leds[i] = color;
  }
}
