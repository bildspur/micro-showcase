#include "LogBook.h"
#include <Arduino.h>

LogBook::LogBook(int rate)
{
  baudRate = rate;
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
  Serial.print(message);
}

void LogBook::println(char *message)
{
  Serial.println(message);
}
