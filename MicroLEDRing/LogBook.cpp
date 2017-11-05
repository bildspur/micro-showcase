#include "LogBook.h"
#include <Arduino.h>

LogBook::LogBook(int rate)
{
  LogBook(rate, true);
}

LogBook::LogBook(int rate, bool logging)
{
  baudRate = rate;
  isLogging = logging;
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
