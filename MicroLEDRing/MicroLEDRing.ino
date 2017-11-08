#include "LogBook.h"
#include "LEDRing.h"

#define NUM_LEDS 144
#define DATA_PIN 8

#define UPDATES_PER_SECOND 100

LogBook book = LogBook(9600);

LEDRing ring = LEDRing(NUM_LEDS);
LEDRing ring2 = LEDRing(NUM_LEDS);

void setup() {
  book.setup();
  book.println("setting up led ring...");

  delay(3000);
  ring.setup<DATA_PIN>();
  ring2.setup<7>();

  ring.all(CRGB::Blue);
  ring2.all(CRGB::Red);
  book.println("ring set!");

  delay(500);
}

void loop() {
  //book.loop();

  ring.all(CRGB::White);
  ring2.all(CRGB::Black);
  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  delay(500);

  ring.all(CRGB::Black);
  ring2.all(CRGB::White);
  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  delay(500);
}
