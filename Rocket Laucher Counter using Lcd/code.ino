#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledPin = 7;
int buzzerPin = 8;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Rocket Launch!");
  delay(2000);
}

void loop() {
  for (int i = 10; i >= 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Countdown: ");
    lcd.print(i);

    delay(1000);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ignition !!!");
  
  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, 1000);  
  delay(3000);
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);

  while (1); // stop program after launch
}
