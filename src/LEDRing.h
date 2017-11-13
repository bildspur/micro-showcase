#ifndef LEDRing_h
#define LEDRing_h

#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#include "LEDRingTypes.h"

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

class LEDRing {
  private:
    int pin;
    int length;

    Direction direction;

    CRGB* leds;

    int directionalIndex(int index);
    int mapIndex(float index);

  public:
    LEDRing(int count, Direction direction = Direction::Default);

    void all(CRGB color);

    void set(CRGB color, float startIndex, float endIndex);

    template<uint8_t DATA_PIN> void setup() {
      this->pin = DATA_PIN;
      FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, length).setCorrection(TypicalLEDStrip);
    }
};
#endif