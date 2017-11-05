#include "LogBook.h"

LogBook book = LogBook(9600);

void setup() {
  book.setup();
}

void loop() {
  book.loop();
}
