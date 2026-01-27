# 🚀 Rocket Launcher Countdown Timer (ATmega328P)

A simple countdown-based rocket launch simulator built on the **Arduino Uno (ATmega328P)**.  
This project controls an LED, a buzzer, and an optional LCD display to show the countdown and simulate ignition.

> ⚠️ **Note:**  
> The low-level C version (using registers) is **not fully working yet** — the buzzer output on `PORTD2` still needs debugging.  
> The Arduino version works correctly.

---

## 🎯 Objective

Build a 10-second countdown system that:

- Displays the countdown  
- Activates an LED  
- Activates a buzzer  
- Shows “Ignition!!!” at launch  

The goal is to learn how the microcontroller works by writing code without depending on Arduino functions.

---

## 🧩 Project Description

The project has two versions:

### ✔️ Working Version (Arduino)
Uses simple functions like `digitalWrite()`, `delay()`, and `tone()` to run the countdown and ignition.

### ⚠️ Incomplete Version (Low-Level C)
This version controls the microcontroller using register statements such as:

- Setting pin direction  
- Writing to pin outputs  
- Creating timing logic manually  

The LED output works, but the buzzer output still needs fixing.

A Wokwi simulation is available for testing:

🔗 **Simulation Link:** https://wokwi.com/projects/442912153261191169

---

## ⚙️ Features

- 10-second countdown  
- LED turns ON during ignition  
- Buzzer activates during ignition  
- Optional LCD display for countdown  
- Can be tested safely on Wokwi  
- Helps understand how microcontroller pins and timing work

---

## 📚 What You Learn

- How to control pins (input/output)  
- How countdown timing works  
- How to activate LEDs and buzzers  
- Difference between simple Arduino code and lower-level C code  
- How to test circuits using Wokwi  

---

## 🛠️ Ignition Flow

1. Display “Rocket Launch!”  
2. Count down from 10 to 0  
3. When countdown reaches zero:  
   - LED turns ON  
   - Buzzer activates  
   - Display shows “Ignition!!!”  
4. Program stops after ignition  

---

## 📝 Future Improvements

- Fix buzzer in the low-level version  
- Add different buzzer tones  
- Add multi-stage countdown events  
- Add an abort switch  
