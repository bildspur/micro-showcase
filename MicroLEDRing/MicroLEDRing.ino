#include "LogBook.h"
#include "LEDRing.h"

#define NUM_LEDS 442
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
  book.println("ring set!");

  delay(500);
}

void loop() {
  //book.loop();

  ring.all(CRGB::Cyan);
  
  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  delay(500);

  //ring.all(CRGB::Blue);
  
  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  delay(500);
}
