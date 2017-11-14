#include "DistanceSensorArray.h"

DistanceSensorArray::DistanceSensorArray(int length) { this->length = length; };

void DistanceSensorArray::tcaSelect(uint8_t i) {
  if (i > 7)
    return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
};

void DistanceSensorArray::setup() {
  Wire.begin();

  loxs = new VL53L0X[length];
  results = new int[length];

  // setup sensor array
  for (uint8_t i = 0; i < length; i++) {
    tcaSelect(i);

    // setup sensor
    results[i] = -1;
    VL53L0X sensor = VL53L0X();

    // init lox sensor
    sensor.init();
    sensor.setTimeout(500);

    // reduce timing budget to 20 ms (default is about 33 ms)
    sensor.setMeasurementTimingBudget(20000);

    loxs[i] = sensor;
  }
};

void DistanceSensorArray::readData() {
  for (uint8_t i = 0; i < length; i++) {
    // switch tca
    tcaSelect(i);

    VL53L0X sensor = loxs[i];

    // measure and save to result array
    results[i] = sensor.readRangeSingleMillimeters();
    if (sensor.timeoutOccurred()) {
      results[i] = -1;
    }
  }
};

int DistanceSensorArray::getLength() { return length; }
