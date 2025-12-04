# 🌃 Street Light Automation System (LDR + PIR + PWM)

An automatic street light control system using an **LDR**, **PIR sensor**, and **LED brightness control**.  
The street light turns ON automatically at night and adjusts brightness based on motion.

Different versions of the system are included:  
1️⃣ Simple ON/OFF using LDR  
2️⃣ Smooth brightness control using PWM  
3️⃣ Night + Motion system using LDR + PIR (final version)

---

## 🎯 Objective

Create an automatic street lighting system that:

- Detects whether it is **day or night** using an LDR  
- Detects **motion** using a PIR sensor  
- Controls LED brightness using PWM  
- Saves energy by dimming the light when no one is around  

---

## 🧩 Project Description

The system checks two conditions:

### **1️⃣ Light Level (LDR)**
- High LDR value → Daytime → Light OFF  
- Low LDR value → Night → Light ON  

### **2️⃣ Motion (PIR Sensor)**
At night:
- **Motion detected → LED at full brightness** (255)  
- **No motion → LED dimmed** (80)  

This mimics real streetlights that brighten when a person or vehicle approaches.

---

## 💡 Street Light Behavior

| Time Condition | Motion | LED State |
|----------------|--------|-----------|
| Daytime | Irrelevant | OFF |
| Night | No Motion | Dim Light |
| Night | Motion Detected | Full Brightness |

---

## ⚙️ Features

- Automatic Day/Night detection  
- Energy-saving dim mode  
- Motion-triggered brightness boost  
- Smooth brightness control using PWM  
- Sensor values printed on Serial Monitor for debugging  

---

## 📚 What You Learn

- How LDR sensors detect light intensity  
- How PIR sensors detect motion  
- How PWM controls LED brightness  
- How to combine multiple sensors for automation  
- How real street light systems save electricity  

---

## 🔄 System Flow

1. Read LDR value  
2. If daytime → Turn light OFF  
3. If night → Check motion sensor  
4. If motion detected → Full brightness  
5. If no motion → Dim light  
6. Repeat continuously  

---

## 📝 Versions Included

### ✔️ **1. Simple ON/OFF Street Light**
Turns LED ON at night and OFF during day.

### ✔️ **2. PWM Street Light**
LED brightness varies gradually based on LDR value.

### ✔️ **3. PIR + LDR Smart Street Light** *(Final Version)*  
Night + Motion → Bright  
Night + No Motion → Dim  
Daytime → OFF  

---

## 📝 Future Improvements

- Add multiple LED street lamps  
- Add real-time clock for scheduled timings  
- Add ambient light compensation  
- Add battery and solar panel simulation  
- Add buzzer alert for motion  

