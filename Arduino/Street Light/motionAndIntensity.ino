int ldrPin = A0;
int pirPin = 2;
int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int pirValue = digitalRead(pirPin);

  if (ldrValue > 600) {  
    analogWrite(ledPin, 0);
    Serial.println("Daytime - Light OFF");
  } 
  else {
    if (pirValue == HIGH) {
      analogWrite(ledPin, 255);
      Serial.println("Night + Motion: Full Brightness");
    } else {
      analogWrite(ledPin, 80);
      Serial.println("Night + No Motion: Dim Light");
    }
  }

  delay(200);
}
