# 🛎️ School Bell Alarm System (ATmega328P + DS3231 RTC)

An automatic school bell system built using an **Arduino Uno**, a **buzzer**, and a **DS3231 Real-Time Clock module**.  
The system rings the bell at scheduled times throughout the day without any manual control.

> ⚠️ **Note:**  
> A low-level version (written using microcontroller registers) will be added later.  
> The bare-metal version is not completed yet because the buzzer output requires debugging.

---

## 🎯 Objective

Create a fully automated school bell that:

- Reads real-time from the DS3231 module  
- Compares the time with a daily bell schedule  
- Rings the buzzer in a repeating pattern  
- Runs continuously throughout the school day  

---

## 🧩 Project Description

The system checks the current hour and minute every second.  
Whenever the minute changes, it compares the new time against a list of scheduled bell times.

If the current time matches one of the entries, the bell rings.

The buzzer rings in a simple alert pattern:

- **5 beeps total**  
- Each beep → **250 ms ON + 250 ms OFF**  
- Total ringing duration → **2.5 seconds**

---

## ⏰ Daily Bell Schedule  
*(Easy to modify in code)*

| Period | Time |
|--------|------|
| Morning Bell | **08:30** |
| Period 1 End | **09:20** |
| Period 2 End | **10:10** |
| Break End | **10:25** |
| Period 3 End | **11:15** |
| Lunch Start | **12:05** |
| Lunch End | **12:40** |
| Period 4 End | **13:35** |
| Period 5 End | **14:25** |
| School End | **15:15** |

You can add, remove, or change these times easily.

---

## ⚙️ Features

- Automatic ringing based on real-time clock  
- Accurate timekeeping using DS3231  
- Clear, simple buzzer pattern  
- Checks schedule only once per minute (efficient)  
- Easy to customize for any institution  

---

A Wokwi simulation is available for testing:

🔗 **Simulation Link:** https://wokwi.com/projects/445537946493478913

---

## 📚 What You Learn

- How to read time from an RTC module  
- How to create a real-world timing system  
- How to compare time values  
- How to drive a buzzer with programmed timing  
- How automation works in embedded projects  

---

## 🔔 Bell Operation Flow

1. Read the current time from the DS3231  
2. If the minute has changed → check schedule  
3. If the hour and minute match a bell time → ring bell  
4. Buzzer rings with a 5-beep pattern  
5. System continues checking time every second  

---

## 📝 Future Improvements

- Add the bare-metal C version  
- Add LCD time display  
- Add manual override / test button  
- Add different bell patterns for different times  
- Add web-based or serial interface for editing schedules  

