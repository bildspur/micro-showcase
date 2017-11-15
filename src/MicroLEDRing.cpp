#include <Arduino.h>

#include "CircleScene.h"
#include "DistanceSensorArray.h"
#include "LogBook.h"
#include "Timer.h"

#define NUM_LEDS_SMALL 160
#define DATA_PIN_SMALL 3

#define NUM_LEDS_MEDIUM 288
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 432
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define SENSOR_TIMER 500

#define BRIGHTNESS 100

#define DEBUG true

// create single led rings
LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

// create led ring ptr array
LEDRingPtr rings[]{&smallRing, &mediumRing, &largeRing};

DistanceSensorArray sensorArray = DistanceSensorArray(5);

// create scenes
CircleScene circleScene = CircleScene();
LightScene *activeScene;

Timer sensorTimer = Timer(SENSOR_TIMER);

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

    // setup scenes
    circleScene.setup(rings);
    activeScene = &circleScene;

    LogBook::println("rings ready!");
}

void loop() {
    // read sensors
    /*
    if(sensorTimer.elapsed()) {
        sensorArray.readData();

        if (DEBUG) {
            for (int i = 0; i < sensorArray.getLength(); i++) {
                Serial.print(i);
                Serial.print(" => ");
                Serial.print(sensorArray.results[i]);
                Serial.print("mm;\t");
            }
            Serial.println();
        }
    }
     */

    // run active scene
    activeScene->loop();

    // write leds
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
