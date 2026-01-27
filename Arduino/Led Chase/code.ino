int ledPins[] = {2, 4, 7, 8, 12};
int count = 5;
int time = 100;
void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // FORWARD
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(time);
    digitalWrite(ledPins[i], LOW);
  }

  // REVERSE
  for (int i = count - 1; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(time);
    digitalWrite(ledPins[i], LOW);
  }
}
