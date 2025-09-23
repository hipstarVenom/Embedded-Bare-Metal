Project Title:

Bare-Metal Rocket Launcher Countdown Timer using Arduino Uno

Objective:

To design and implement a precise countdown timer for a rocket launch simulation using bare-metal programming on the Arduino Uno, demonstrating direct hardware control without Arduino libraries.

Description:

This project features a countdown system that triggers a simulated rocket launch using an LED and buzzer. The countdown timer is implemented using ATmega328P registers and Timer1 interrupts instead of Arduino library functions, allowing precise timing and deeper understanding of microcontroller internals.

Key features:

Configurable countdown timer (10 seconds default).

LED and buzzer trigger at the end of countdown to simulate ignition.

Bare-metal programming: direct register manipulation (DDRx, PORTx, TCCR1A/B, OCR1A).

Optional I2C LCD display for countdown visualization (can be replaced with LEDs for fully bare-metal implementation).

Safe simulation on Wokwi before real-world deployment.

Learning Outcomes:

Understanding of GPIO configuration and register-level I/O control.

Working knowledge of hardware timers and interrupts.

Exposure to bare-metal embedded programming, bypassing Arduino abstractions.

Ability to simulate real-world hardware systems with precise timing.