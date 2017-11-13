#include "LogBook.h"
#include <Arduino.h>

int LogBook::baudRate;
bool LogBook::isLogging;

void LogBook::setup(int baudRate, bool isLogging) {
  LogBook::isLogging = isLogging;
  LogBook::baudRate = baudRate;

  Serial.begin(baudRate);
  Serial.println("Logbook started!");
}

void LogBook::print(String message) {
  if (isLogging)
    Serial.print(message);
}

void LogBook::println(String message) {
  if (isLogging)
    Serial.println(message);
}
