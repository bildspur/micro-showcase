#ifndef LogBook_h
#define LogBook_h
#include "Controller.h"
class LogBook : public Controller
{
  private:
    int baudRate;

  public:
    LogBook(int rate);

    virtual void setup();
    virtual void loop();

    void print(char *message);
    void println(char *message);
};
#endif
