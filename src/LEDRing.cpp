#include "LEDRing.h"

LEDRing::LEDRing(int length, Direction direction) {
  this->length = length;
  this->direction = direction;

  leds = new CRGB[length];

  // clear arrays
  for (int i = 0; i < length; ++i)
    leds[i] = CRGB::Black;
}

void LEDRing::all(CRGB color) {
  for (int i = 0; i < length; i++) {
    leds[i] = color;
  }
}

void LEDRing::set(CRGB color, float startIndex, float endIndex) {
  int s = mapIndex(startIndex);
  int e = mapIndex(endIndex);
  int count = e - s;

  /*
  Serial.print("Start: ");
  Serial.print(s);
  Serial.print(" End: ");
  Serial.print(e);
  Serial.print(" Count: ");
  Serial.println(count);
  */

  for (int i = 0; i < count; i++) {
    leds[directionalIndex(i)] = color;
  }
}

int LEDRing::mapIndex(float index) { return round(length * index); }

int LEDRing::directionalIndex(int index) {
  if (direction == Direction::Inverted)
    return length - index;

  return index;
}
