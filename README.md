# 🔧 Embedded & Bare-Metal Projects  
A collection of embedded system projects built using the **Arduino Uno (ATmega328P)**.  
This repository includes both **Arduino implementations** and **early bare-metal experiments** using register-level programming.

The goal of this repo is to explore sensors, actuators, simple automation systems, and low-level microcontroller behavior through hands-on projects.

---

## 📂 Projects Included

### 🚀 Rocket Launch Countdown  
A 10-second countdown with LED and buzzer ignition.  
Includes a working Arduino version and a partially complete bare-metal version (buzzer debugging in progress).

### 🛎️ School Bell System (DS3231 RTC)  
Automated bell ringing at preset times using an RTC module.  
Reliable timing and easy schedule modification.

### 🔢 Keypad Security System  
User creates a 4-digit password.  
Correct password → green LED.  
Incorrect password → warning LED flash sequence.

### 🚦 Traffic Light Controller  
Red → Yellow → Green timing cycle.  
Includes both Arduino and fully working bare-metal versions.

### 🌃 Smart Street Light (LDR + PIR)  
Adaptive street light that:  
- Turns OFF during the day  
- Dims at night with no motion  
- Brightens fully when motion is detected  

Includes simpler versions such as:  
- Basic LDR ON/OFF light  
- Smooth PWM brightness control

### 💡 LED Chase / Knight Rider Effect  
A sequential LED animation inspired by the Knight Rider car light.  
- LEDs chase from left → right → left  
- Arduino version included  
- Bare-metal version implemented with direct register control  
Great for refreshing timing, arrays, and GPIO control.

---

## 🎯 What This Repository Demonstrates

- Sensor interfacing (LDR, PIR, RTC, Keypad)  
- Output control (digital LEDs, PWM brightness, buzzer)  
- I²C communication basics  
- Simple automation system design  
- Introductory bare-metal concepts (DDRx, PORTx, timing)  
- Clean, readable project structure  

This collection reflects practical learning and experimentation across multiple embedded domains.

---

## 🛠️ Current Status

✔ All Arduino versions work fully  
⚠ Bare-metal versions are actively being improved  
✔ All projects tested and verified in Wokwi Simulator  

Additional projects and refined bare-metal implementations will continue to be added.

---

## 📌 Purpose

This repository serves as a **showcase of embedded system experiments**, blending hobby electronics with early firmware engineering techniques.  
It documents the learning process and progression from high-level Arduino coding to low-level microcontroller control.

