#include <Arduino.h>

#include "DistanceSensorArray.h"
#include "LEDRing.h"
#include "LogBook.h"
#include "MicroUtils.h"

#define NUM_LEDS_SMALL 160
#define DATA_PIN_SMALL 3

#define NUM_LEDS_MEDIUM 300
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 432
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define BRIGHTNESS 255

LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

DistanceSensorArray sensorArray = DistanceSensorArray(1);

CHSV baseColor = fromHSV(180, 100, 100);

void setup() {
  LogBook::setup(9600);
  LogBook::println("setting up led rings...");

  // delay(1000);

  // setup rings
  smallRing.setup<DATA_PIN_SMALL>();
  mediumRing.setup<DATA_PIN_MEDIUM>();
  largeRing.setup<DATA_PIN_LARGE>();

  // setup sensors
  sensorArray.setup();

  // setup brightness
  FastLED.setBrightness(BRIGHTNESS);

  LogBook::println("rings ready!");
}

void loop() {
  smallRing.set(baseColor, 0, 1);
  mediumRing.set(baseColor, 0, 1);
  largeRing.set(baseColor, 0, 1);

  // read
  sensorArray.readData();

  for (int i = 0; i < sensorArray.getLength(); i++) {
    Serial.print(i);
    Serial.print(" => Distance (mm): ");
    Serial.println(sensorArray.results[i]);
  }

  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
