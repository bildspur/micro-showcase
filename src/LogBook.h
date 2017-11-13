#ifndef LogBook_h
#define LogBook_h

#include <Arduino.h>

class LogBook {
private:
  static int baudRate;
  static bool isLogging;

  LogBook();

public:
  static void setup(int baudRate, bool isLogging = true);

  static void print(String message);
  static void println(String message);
};
#endif
