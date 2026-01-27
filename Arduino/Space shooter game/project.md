# Arduino Space Shooter

Simple text-based space shooter game on Arduino using an SSD1306 OLED and joystick.

Wokwi Simulation:  
https://wokwi.com/projects/449529236563364865

---

## Components

- Arduino Uno / Nano  
- SSD1306 128x64 OLED (I2C)  
- Analog Joystick  
- Buzzer (optional for sound)  
- Jumper Wires  

---

## Setup

### OLED (I2C)

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Joystick

| Joystick Pin | Arduino Pin |
|--------------|-------------|
| VERT | A0 |
| VHOR | A1 |
| SW  | Not used |
| 5V  | 5V |
| GND | GND |

### Buzzer (Optional)

| Buzzer Pin | Arduino Pin |
|------------|-------------|
| + | D9 |
| - | GND |

---

## Game Elements

- **Player:** `m` (bottom of screen)  
- **Bullet:** `|` (moves upward)  
- **Enemy:** `O` (falls downward)  

---

## Game Loop

- Read joystick for player movement  
- Update bullet position  
- Update enemy position  
- Check collisions  
- Draw player, bullet, and enemy  
- Refresh OLED display  

---

## Considerations

- Maintain screen boundaries  
- Apply joystick deadzone  
- Use millis() for timing  
- Keep OLED updates efficient  
- Adjust enemy speed for difficulty  

---

## Collision of Bullet and Enemies

- Bullet and enemy positions are checked for overlap  
- On collision: remove bullet and enemy  
- New enemy will respawn  

---

## Multiple Enemies and Collision

- Use an array/list of enemies  
- Update each active enemy  
- Check bullet collision with all enemies  
- Respawn enemies when removed or off-screen  

---

## Sound Effects (Optional)

- Buzzer can play shot, hit, or alert tones  
- Simple tones can be triggered on events  

---

## Description

This project demonstrates a basic shooter game built entirely on Arduino hardware using text characters on a 128x64 OLED display. The joystick controls the player, enemies fall from the top, and bullets fire automatically. It is a small but complete example of handling input, movement, drawing, and collision in an embedded game.

