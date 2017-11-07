#include "LogBook.h"
#include "LEDRing.h"

#define NUM_LEDS 144
#define DATA_PIN 8

#define UPDATES_PER_SECOND 100

LogBook book = LogBook(9600);
LEDRing ring = LEDRing(NUM_LEDS);

void setup() {
  book.setup();
  book.println("setting up led ring...");

  delay(3000);
  ring.setup<DATA_PIN>();

  ring.all(CRGB::Blue);
  FastLED.show();

  book.println("ring set!");
}

void loop() {
  //book.loop();

  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
