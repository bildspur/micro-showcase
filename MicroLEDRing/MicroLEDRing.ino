#include "LogBook.h"
#include "LEDRing.h"

LogBook book = LogBook(9600);
LEDRing ring = LEDRing(144);

void setup() {
  book.setup();

  ring.setup<8>();

  ring.clear();
  ring.light(CRGB::Aqua);
  ring.show();
}

void loop() {
  book.loop();
}
