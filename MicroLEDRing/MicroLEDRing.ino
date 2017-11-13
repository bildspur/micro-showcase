#include "LogBook.h"
#include "LEDRing.h"

#define NUM_LEDS_SMALL 144
#define DATA_PIN_SMALL 3

#define NUM_LEDS_MEDIUM 144
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 144
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define BRIGHTNESS 64

LogBook book = LogBook(9600);

LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

void setup() {
  book.setup();
  book.println("setting up led ring...");

  delay(1000);

  // setup rings
  smallRing.setup<DATA_PIN_SMALL>();
  mediumRing.setup<DATA_PIN_MEDIUM>();
  largeRing.setup<DATA_PIN_LARGE>();

  // setup brightness
  FastLED.setBrightness( BRIGHTNESS);

  book.println("ring set!");
}

void loop() {


  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
