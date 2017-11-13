#include "LogBook.h"
#include "LEDRing.h"
#include "MicroUtils.h"

#define NUM_LEDS_SMALL 160
#define DATA_PIN_SMALL 3

#define NUM_LEDS_MEDIUM 300
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 432
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define BRIGHTNESS 32

LogBook book = LogBook(9600);

LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

CHSV baseColor = fromHSV(180, 100, 100);

void setup() {
  book.setup();
  book.println("setting up led rings...");

  //delay(1000);

  // setup rings
  smallRing.setup<DATA_PIN_SMALL>();
  mediumRing.setup<DATA_PIN_MEDIUM>();
  largeRing.setup<DATA_PIN_LARGE>();

  // setup brightness
  FastLED.setBrightness(BRIGHTNESS);

  mediumRing.set(CRGB::Green, 0, 1);
  largeRing.set(CRGB::Blue, 0, 1);

  book.println("rings ready!");
}

void loop() {
  smallRing.set(baseColor, 0, 1);

  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
