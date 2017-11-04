class Controller {
  public:
    virtual void setup() = 0;
    virtual void update() = 0;

    virtual ~Controller() {}
};
