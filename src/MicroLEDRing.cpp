#include <Arduino.h>

#include "CircleScene.h"
#include "LogBook.h"
#include "Timer.h"
#include "ColorScene.h"

#define NUM_LEDS_SMALL 160
#define DATA_PIN_SMALL 3

#define NUM_LEDS_MEDIUM 288
#define DATA_PIN_MEDIUM 4

#define NUM_LEDS_LARGE 432
#define DATA_PIN_LARGE 5

#define UPDATES_PER_SECOND 100

#define BRIGHTNESS 100

#define SENSORS_ACTIVE true

#define SENSOR_TIMER 200

#define DEBUG false

#define IS_ONLY_LIGHT true

// create single led rings
LEDRing smallRing = LEDRing(NUM_LEDS_SMALL);
LEDRing mediumRing = LEDRing(NUM_LEDS_MEDIUM);
LEDRing largeRing = LEDRing(NUM_LEDS_LARGE);

// create led ring ptr array
LEDRingPtr rings[]{&smallRing, &mediumRing, &largeRing};

DistanceSensorArray sensorArray = DistanceSensorArray(5);

// create scenes
CircleScene circleScene = CircleScene();
ColorScene colorScene = ColorScene();
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
    circleScene.setup(rings, &sensorArray);
    colorScene.setup(rings);

    if (IS_ONLY_LIGHT)
        activeScene = &colorScene;
    else
        activeScene = &circleScene;

    LogBook::println("rings ready!");
}

void loop() {
    // read sensors
    if (SENSORS_ACTIVE && sensorTimer.elapsed()) {
        sensorArray.readData();

        if (DEBUG) {
            Serial.print(int(millis() / 1000 / 60 / 60));
            Serial.print(" h ");
            Serial.print(int(millis() / 1000 / 60));
            Serial.print(" m ");
            Serial.print(int(millis() / 1000));
            Serial.print(" s ");
            Serial.print(": ");

            for (int i = 0; i < sensorArray.getLength(); i++) {
                Serial.print(i);
                Serial.print(" => ");
                Serial.print(sensorArray.results[i]);
                Serial.print("mm;\t");
            }
            Serial.println();
        }
    }

    // run active scene
    activeScene->loop();

    // write leds
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
