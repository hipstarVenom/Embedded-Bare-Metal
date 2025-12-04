# 🚗 Knight Rider LED Chase (ATmega328P)

A simple LED animation inspired by the iconic Knight Rider car light effect.  
This project uses multiple LEDs connected to an **Arduino Uno (ATmega328P)** to create a smooth back-and-forth scanning effect.

> ⚠️ **Note:**  
> This is a basic animation project meant for refreshing Arduino fundamentals.  

---

## 🎯 Objective

Build a smooth LED scanning effect that:

- Moves from left → right  
- Moves from right → left  
- Avoids repeating the end LEDs  
- Creates a clean “KITT” visual animation  

This project helps reinforce basic embedded concepts through a fun and simple LED exercise.

---

## 🧩 Project Description

The Knight Rider effect is created by lighting LEDs sequentially:

### ✔️ Forward Pass  
LEDs turn ON one at a time from left to right.

### ✔️ Reverse Pass  
The sequence continues back from right to left, skipping the endpoints to avoid flickering.

The animation runs continuously in an endless loop.

---

## ⚙️ Features

- Smooth left-to-right and right-to-left scanning  
- Simple to build and perfect for beginners  
- Uses arrays for easy LED control  
- Adjustable speed  
- Can be extended with fade effects (PWM)

---

## 📚 What You Learn

- How to control multiple LEDs using arrays  
- How to create forward and reverse loops  
- Timing and animation creation using delays  
- How to produce visual effects using simple logic  
- Basics of embedded programming and sequencing

---

## 🛠️ Animation Flow

1. Turn ON LED 1 → turn OFF  
2. Turn ON LED 2 → turn OFF  
3. Turn ON LED 3 → turn OFF  
4. Continue to the last LED  
5. Reverse the sequence  
6. Repeat indefinitely  

This creates the classic Knight Rider “scanner” look.

---

## 📝 Future Improvements

- Add PWM fading trails for a more realistic effect  
- Add acceleration/deceleration animation  
- Add double-sided scanning (two lights moving toward the center)  
- Convert project to low-level register control  
- Create a small game using the chase effect  

