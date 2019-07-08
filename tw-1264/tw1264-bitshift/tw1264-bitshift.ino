int rck_pin = 8;
int srck_pin = 12;
int serin_pin = 11;

void setup() {
  pinMode(rck_pin, OUTPUT);
  pinMode(srck_pin, OUTPUT);
  pinMode(serin_pin, OUTPUT);
}

void loop() {
  for (int i=0;i<8;i++)
  {
    digitalWrite(rck_pin, LOW);
    shiftOut(serin_pin, srck_pin, LSBFIRST, 1<<i);
    digitalWrite(rck_pin, HIGH);
    delay(1000);
  }
}
