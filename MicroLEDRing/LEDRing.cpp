#include "LEDRing.h"

LEDRing::LEDRing(int count) {
  this->count = count;
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
