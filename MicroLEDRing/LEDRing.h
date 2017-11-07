#ifndef LEDRing_h
#define LEDRing_h

#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

class LEDRing {
  private:
    int pin;
    int count;

    CRGB* leds;

  public:
    LEDRing(int count);

    void all(CRGB color);

    template<uint8_t DATA_PIN> void setup() {
      this->pin = DATA_PIN;
      FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, count).setCorrection(TypicalLEDStrip);
    }
};
#endif
