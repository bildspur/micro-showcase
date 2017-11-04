using namespace std;

Logbook log = LogBook(9600);

void setup() {
  log.setup();
}

void loop() {
  log.update();
}
