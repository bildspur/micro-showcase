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

  sensors = new VL53L0XPtr[length];
  results = new int[length];

  // setup sensor array
  for (uint8_t i = 0; i < length; i++) {
    tcaSelect(i);

    auto sensor = new VL53L0X();
    sensor->init();
    sensor->setTimeout(500);

    // reduce timing budget to 20 ms (default is about 33 ms)
    sensor->setMeasurementTimingBudget(33000);
    sensors[i] = sensor;
  }
};

void DistanceSensorArray::readData() {
  for (uint8_t i = 0; i < length; i++) {
    // switch tca
    tcaSelect(i);
    VL53L0XPtr sensor = sensors[i];

    // measure and save to result array
    results[i] = sensor->readRangeSingleMillimeters();
    if (sensor->timeoutOccurred()) {
      results[i] = -1;
    }
  }
};

int DistanceSensorArray::getLength() { return length; }
