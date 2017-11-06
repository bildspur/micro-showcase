#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>

// NodeMCU Digital Pins
#define D0  16
#define D1  5  // I2C Bus SCL (clock)
#define D2  4  // I2C Bus SDA (data)
#define D3  0
#define D4  2  // Same as "LED_BUILTIN", but inverted logic
#define D5  14 // SPI Bus SCK (clock)
#define D6  12 // SPI Bus MISO 
#define D7  13 // SPI Bus MOSI
#define D8  15 // SPI Bus SS (CS)
#define D9  3  // RX0 (Serial console)
#define D10 1  // TX0 (Serial console)

#define LED_PIN D5
#define NUM_LEDS 144
#define BRIGHTNESS 64
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
  // power saftey delay
  delay(3000);

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  setColors(CRGB::Aqua);
  FastLED.show();
  delay(300);

  setColors(CRGB::White);
  FastLED.show();
  delay(300);
  
  //FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void setColors(CRGB color)
{
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
}

