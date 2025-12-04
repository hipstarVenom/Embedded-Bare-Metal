# 🔧 Embedded & Bare-Metal Projects  
A collection of small embedded systems projects built using the **Arduino Uno (ATmega328P)**.  
This repository contains both **Arduino-level implementations** and **early bare-metal attempts** using register programming.

The goal of this repo is to explore sensors, actuators, real-world logic systems, and low-level microcontroller behavior through simple, practical projects.

---

## 📂 Projects Included

### 🚀 Rocket Launch Countdown  
10-second countdown with LED and buzzer ignition.  
Includes Arduino version and an incomplete bare-metal version (buzzer under debugging).

### 🛎️ School Bell System (DS3231 RTC)  
Automatic bell rings at scheduled times using RTC.  
Simple, reliable, and easy to customize.

### 🔢 Keypad Security System  
User sets a 4-digit password.  
Correct password → green LED.  
Wrong password → warning LED blinks.

### 🚦 Traffic Light Controller  
Red → Yellow → Green cycle with fixed timing.  
Contains both Arduino and working bare-metal versions.

### 🌃 Smart Street Light (LDR + PIR)  
Automatic streetlight that:  
- Turns OFF during the day  
- Dims at night when no motion  
- Brightens when motion is detected  

Also includes:  
- Basic LDR ON/OFF version  
- Smooth PWM brightness version

---

## 🎯 What This Repository Shows

- Sensor interfacing (LDR, PIR, RTC, Keypad)  
- LED control (digital + PWM brightness)  
- I²C communication  
- Basic automation logic  
- Introduction to bare-metal concepts (DDRx, PORTx, timing)  
- Clean step-by-step embedded projects  

This is a growing collection made for learning, experimenting, and showcasing small embedded ideas.

---

## 🛠️ Status

✔ Arduino versions work fully  
⚠ Bare-metal versions are in progress  
✔ All projects tested in Wokwi Simulator  

More projects and improved bare-metal code will be added over time.

---

## 📌 Purpose

This repository acts as a **showcase of embedded system experiments**, combining hobby electronics with early firmware engineering concepts.

