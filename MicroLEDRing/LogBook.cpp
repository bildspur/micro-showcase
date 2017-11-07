#include "LogBook.h"
#include <Arduino.h>

LogBook::LogBook(int baudRate, bool isLogging)
{
  this->baudRate = baudRate;
  this->isLogging = isLogging;
}

void LogBook::setup()
{
  Serial.begin(baudRate);
  Serial.println("Logbook started!");
}

void LogBook::loop()
{
}

void LogBook::print(char *message)
{
  if (isLogging)
    Serial.print(message);
}

void LogBook::println(char *message)
{
  if (isLogging)
    Serial.println(message);
}
