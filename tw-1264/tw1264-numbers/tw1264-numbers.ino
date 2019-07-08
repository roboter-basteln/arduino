int rck_pin = 8;
int srck_pin = 12;
int serin_pin = 11;
int digits[10] = { 
	4+8+16+32+64+128,
	32+64,
	128+64+2+8+16,
	64+32+2+16+128,
	4+2+32+64,
	128+4+2+32+16,
	128+4+2+8+32+16,
	64+32+128,
	128+4+64+2+8+32+16,
	128+4+2+64+32+16
};

void setup() {
  pinMode(rck_pin, OUTPUT);
  pinMode(srck_pin, OUTPUT);
  pinMode(serin_pin, OUTPUT);
}

void loop() {
  for (int digit=0; digit<=9; digit++)
  {
    digitalWrite(rck_pin, LOW);
    shiftOut(serin_pin, srck_pin, LSBFIRST, 28+0*digits[digit]+(digit%2));
    digitalWrite(rck_pin, HIGH);
    delay(1000);
  }
}
