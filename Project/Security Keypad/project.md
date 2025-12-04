# 🔢 Security Keypad System (Arduino Uno)

A simple security lock system built using a **4×4 keypad**, **LED indicator**, and a **warning LED**.  
The user creates a 4-digit password, and then must enter the same password to unlock.

This project demonstrates basic keypad input, password handling, and LED output control.

> ⚠️ A low-level (register-based) version will be added later.  
> Bare-metal code is not written yet.

---

## 🎯 Objective

Build a keypad-based security system that:

- Allows the user to set a 4-digit password  
- Accepts user input to unlock  
- Turns on a green LED when the password is correct  
- Blinks a red LED when the password is wrong  
- Keeps running in a loop for continuous checking  

---

## 🧩 Project Description

The system works in two stages:

### **1️⃣ Password Setup**
- User presses any 4 number keys on the keypad  
- These digits become the system password  
- Password is stored until reset  

### **2️⃣ Password Verification**
- User enters another 4 digits  
- System compares them with the saved password  

If correct:
- Green LED turns ON for **5 seconds**

If wrong:
- Red LED blinks **3 times**  
  (1 second ON + 1 second OFF each time)

After each attempt, the system resets and waits for another input.

---

## 🎛️ Components

- 4×4 Matrix Keypad  
- Green LED (success indicator)  
- Red LED (warning indicator)  
- Arduino Uno  
- Jumper wires  
- Breadboard  

---

## ⚙️ Features

- Simple password creation  
- Clear success and failure indicators  
- Stores the password until reboot  
- Accepts only numeric digits  
- Easy to modify: you can change password length or LED behavior  

---
A Wokwi simulation is available for testing:

🔗 **Simulation Link:** https://wokwi.com/projects/444607773810486273
---

## 📚 What You Learn

- How keypad matrices work  
- How to read keypad input using a library  
- How to build a basic password system  
- How to compare strings in Arduino  
- How to control LEDs for status indication  

---

## 🔐 System Flow

1. System starts  
2. User enters a 4-digit password (setup)  
3. User enters another 4 digits (verification)  
4. System checks:  
   - ✔️ If matched → green LED ON  
   - ❌ If wrong → red LED blinks 3 times  
5. System resets and waits for next input  

---

## 📝 Future Additions

- Add the bare-metal version (register-based logic)  
- Add buzzer alert for wrong password  
- Add LCD display for user prompts  
- Add lockout system after 3 failed attempts  
- Add EEPROM to save password permanently  

