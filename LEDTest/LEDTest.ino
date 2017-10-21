#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


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

#define STATUS_PIN D2
#define LED_PIN D1
#define NUMPIXELS 30

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

bool s = false;

void setup() {
  pixels.begin();
  pixels.show();

  pinMode(STATUS_PIN, OUTPUT);
}

void loop() {
  /*
    for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(100);

    if (s)
    {
      digitalWrite(STATUS_PIN, HIGH);
      s = false;
    }
    else
    {
      digitalWrite(STATUS_PIN, LOW);
      s = true;
    }
    }
  */
  theaterChase(pixels.Color(127, 127, 127), 50); // White
  theaterChase(pixels.Color(127, 0, 0), 50); // Red
  theaterChase(pixels.Color(0, 0, 127), 50); // Blue
  pixels.show();
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, c);  //turn every third pixel on
      }
      pixels.show();

      delay(wait);

      for (uint16_t i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}
