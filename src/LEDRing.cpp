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
    set(color, 0f, 1f);
}

void LEDRing::set(CRGB color, float startIndex, float endIndex) {
    int s = mapIndex(startIndex);
    int e = mapIndex(endIndex);
    int count = e - s;

    for (int i = s; i < count; i++) {
        leds[directionalIndex(i) % length] = color;
    }
}

int LEDRing::mapIndex(float index) { return static_cast<int>(round(length * index)); }

int LEDRing::directionalIndex(int index) {
    if (direction == Direction::Inverted)
        return length - index;

    return index;
}
