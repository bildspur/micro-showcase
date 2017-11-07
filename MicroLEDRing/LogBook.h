#ifndef LogBook_h
#define LogBook_h
#include "Controller.h"
class LogBook : public Controller
{
  private:
    int baudRate;
    bool isLogging;

  public:
    LogBook(int baudRate, bool isLogging = true);

    virtual void setup();
    virtual void loop();

    void print(char *message);
    void println(char *message);
};
#endif
