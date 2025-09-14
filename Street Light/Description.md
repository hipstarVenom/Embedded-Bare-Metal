Project Name: Smart Streetlight Using Photoresistor



Description:

This project demonstrates an automated streetlight system that turns on or off based on ambient light levels. A photoresistor (LDR) senses the surrounding light intensity. When it gets dark, the streetlight (represented by an LED) turns on automatically, and when it’s bright, the light turns off.



How It Works:



Sensing Light: The photoresistor changes its resistance based on light intensity. In bright conditions, resistance is low; in darkness, resistance is high.



Reading Values: The Arduino reads the voltage from the LDR using an analog input pin.



Decision Making: The Arduino compares the reading with a preset threshold value.



If the light level is below the threshold → Turn on the LED (streetlight).



If the light level is above the threshold → Turn off the LED.



Output: The LED simulates the streetlight turning on or off based on ambient light.

Applications:



Energy-efficient streetlights that save power.



Automated lighting systems for smart cities.

