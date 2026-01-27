int ldrPin = A0;
int ledPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrValue = analogRead(ldrPin); 
  float brightness = (-255.0/1023.0) * ldrValue + 255; 
  if (brightness < 0) brightness = 0;
  if (brightness > 255) brightness = 255;
  analogWrite(ledPin, (int)brightness);
  
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print("  Brightness: ");
  Serial.println(brightness);
  
  delay(100);
}
