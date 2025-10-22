#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

int buzzPin = 12;

int bellTimes[][2] = {
  {8, 30},
  {9, 20},
  {10, 10},
  {10, 25},
  {11, 15},
  {12, 5},
  {12, 40},
  {13, 35},
  {14, 25},
  {15, 15},
};

int lastMinute = -1;
int numBells = sizeof(bellTimes) / sizeof(bellTimes[0]);

void setup() {
  Wire.begin();      // initializes SDA (A4) and SCL (A5)
  rtc.begin();
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("School Bell System Started");
}

void loop() {
  DateTime now = rtc.now();   // read current time from RTC
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());

  if (now.minute() != lastMinute) {
    lastMinute = now.minute();
    for (int i = 0; i < numBells; i++) {
      if (now.hour() == bellTimes[i][0] && now.minute() == bellTimes[i][1]) {
        ringBell();
      }
    }
  }

  delay(1000);
}

void ringBell() {
  Serial.println("Bell Ringing!");
  
  // play tone (1000 Hz for 2.5 seconds total)
  for (int i = 0; i < 5; i++) {
    tone(buzzPin, 1000);   // play 1000Hz sound
    delay(250);
    noTone(buzzPin);       // stop the tone
    delay(250);
  }
}
