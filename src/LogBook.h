#ifndef LogBook_h
#define LogBook_h

class LogBook
{
  private:
    static int baudRate;
    static bool isLogging;

    LogBook();

  public:
    static void setup(int baudRate, bool isLogging = true);

    static void print(char *message);
    static void println(char *message);
};
#endif
