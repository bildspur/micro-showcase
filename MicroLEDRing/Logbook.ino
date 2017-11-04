class Logbook : public Controller
{
  private:
    int baudRate;

  public:
    public Logbook(int rate)
    {
      baudRate = rate;
    }

    virtual void setup()
    {
      Serial.begin(baudRate);
      Serial.println("Logbook started!");
    }

    virtual void update()
    {
    }

    void print(char *message)
    {
      Serial.print(message);
    }

    void println(char *message)
    {
      Serial.println(message);
    }
};
