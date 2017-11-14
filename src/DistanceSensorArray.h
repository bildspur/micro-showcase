#ifndef DistanceSensorArray_h
#define DistanceSensorArray_h

#include <VL53L0X.h>

#include <Wire.h>
extern "C" {
#include "utility/twi.h" // from Wire library, so we can do bus scanning
}

#define TCAADDR 0x70

class DistanceSensorArray {
private:
  VL53L0X *loxs;
  int length;

  void tcaSelect(uint8_t i);

public:
  DistanceSensorArray(int length);
  void setup();
  void readData();

  int getLength();

  int *results;
};
#endif
