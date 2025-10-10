// Traffic controller

// variables
int redPin = 13;
int bluePin = 8;
int greenPin = 12;

// delay
int delay_time = 5000;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
  delay(delay_time);
  
  digitalWrite(redPin,HIGH);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(delay_time);

  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(delay_time);
}
