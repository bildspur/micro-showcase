#include <Arduino.h>

#include "CircleScene.h"
#include "DistanceSensorArray.h"
#include "LEDRing.h"
#include "LightScene.h"
#include "LogBook.h"
#include "MicroUtils.h"

#define NUM_LEDS_SMALL 160
#define DATA_PIN_SMALL 2

#define NUM_LEDS_MEDIUM 12 // 300
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 12 // 432
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define BRIGHTNESS 255

// create single led rings
LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

// create led ring ptr array
LEDRingPtr rings[]{&smallRing, &mediumRing, &largeRing};

DistanceSensorArray sensorArray = DistanceSensorArray(1);

// create scenes
CircleScene circleScene = CircleScene();
LightScene *activeScene;

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

  /*
  smallRing.set(baseColor, 0, 1);
  mediumRing.set(baseColor, 0, 1);
  largeRing.set(baseColor, 0, 1);
  */

  // setup brightness
  FastLED.setBrightness(BRIGHTNESS);

  // setup scenes
  circleScene.setup(rings);
  activeScene = &circleScene;

  LogBook::println("rings ready!");
}

void loop() {
  // read sensors
  /*
  sensorArray.readData();

  for (int i = 0; i < sensorArray.getLength(); i++) {
    Serial.print(i);
    Serial.print(" => Distance (mm): ");
    Serial.println(sensorArray.results[i]);
  }

  Serial.println("===========");
  */

  // run active scene
  activeScene->loop();

  // write leds
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
