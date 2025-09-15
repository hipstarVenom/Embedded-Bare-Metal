int datapin = 2; 
int clockpin = 3;
int latchpin = 4;

void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 4; i++) {
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, MSBFIRST, 1 << i);  
    digitalWrite(latchpin, HIGH);
    delay(500);
  }
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  digitalWrite(latchpin, HIGH);
  delay(500);
}
