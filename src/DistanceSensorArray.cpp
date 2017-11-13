#include "DistanceSensorArray.h"

DistanceSensorArray::DistanceSensorArray(int length) {
  this->length = length;

  loxs = new Adafruit_VL53L0X[length];
  results = new int[length];

  // setup sensor array
  for (int i = 0; i < length; i++) {
    loxs[i] = Adafruit_VL53L0X();
    results[i] = -1;
  }
};

void DistanceSensorArray::tcaSelect(uint8_t i) {
  if (i > 7)
    return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
};

void DistanceSensorArray::setup() {
  Wire.begin();

  // init lox sensors
  for (uint8_t i = 0; i < length; i++) {
    tcaSelect(i);

    if (!loxs[i].begin()) {
      Serial.print("Failed to boot VL53L0X [");
      Serial.print(i);
      Serial.println("]");
    }
  }
};

void DistanceSensorArray::readData() {
  VL53L0X_RangingMeasurementData_t measure;

  for (uint8_t i = 0; i < length; i++) {
    // switch tca
    tcaSelect(i);

    // measure
    loxs[i].rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {
      results[i] = measure.RangeMilliMeter;
    } else {
      results[i] = -1;
    }
  }
};

int DistanceSensorArray::getLength() { return length; }
