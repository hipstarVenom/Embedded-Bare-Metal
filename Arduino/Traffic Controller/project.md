# 🚦 Traffic Light Controller (ATmega328P + Arduino Uno)

A basic traffic signal simulation using **three LEDs** (Red, Yellow, Green).  
This project cycles through standard traffic light states using both Arduino code and a low-level C version.

> ⚠️ The low-level version works for LEDs but will be improved later.  
> Timing and state handling may be refined in future updates.

---

## 🎯 Objective

Create a simple traffic light system that:

- Turns **Red** ON  
- Switches to **Yellow**  
- Then turns **Green** ON  
- Repeats continuously  

Each state lasts **5 seconds** (adjustable).

---

## 🧩 Project Description

The controller runs in a loop:

1. **Red Light ON**  
2. **Red + Yellow ON** (transition)  
3. **Green Light ON**  
4. Reset and repeat  

This mimics a normal traffic signal sequence.

Two versions of the project exist:

### ✔️ Arduino Version (Simple)  
Uses `pinMode()`, `digitalWrite()`, and `delay()` for easy LED control.

### ✔️ Low-Level C Version  
Controls the LEDs using ATmega328P port registers.

---

## 🚥 Traffic Light Timing

| Light State | Duration |
|-------------|----------|
| 🔴 Red | 5 seconds |
| 🔴🟡 Red + Yellow | 5 seconds |
| 🟢 Green | 5 seconds |

You can change the delay values to adjust timing.

---

## ⚙️ Features

- Simple state-based traffic sequence  
- Easy LED wiring (Red, Yellow, Green)  
- Arduino and low-level C versions included  
- Clean timing cycle  
- Beginner-friendly embedded project  

---

A Wokwi simulation is available for testing:

🔗 **Simulation Link:** https://wokwi.com/projects/444443314479916033

---
## 📚 What You Learn

- How LEDs are controlled using microcontroller pins  
- How to time events in embedded systems  
- Difference between Arduino functions and direct register control  
- How traffic lights operate in a cycle  

---

## 🔄 System Flow

1. Set **Red ON**, wait  
2. Turn on **Yellow** along with Red  
3. Switch to **Green ON**, turn others off  
4. Loop forever  

---

## 📝 Future Improvements

- Add a pedestrian button  
- Add buzzer or countdown display  
- Add 7-segment signal timer  
- Add lane-based or smart traffic logic  
- Improve low-level version with better structure  
