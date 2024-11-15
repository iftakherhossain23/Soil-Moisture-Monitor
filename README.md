# Soil Moisture Monitor
This Arduino program monitors soil moisture levels using an analog soil moisture sensor, displays the readings on an OLED screen, and indicates dryness through an LED. When the soil is dry, the LED will light up, and when it's moist, the LED will turn off. The moisture levels are also displayed on a small OLED screen connected via an I2C serial communication protocol.

## Components
- Arduino Uno
- Soil Moisture Sensor
- OLED Display (SSD1306, 128x64)
- LED
- Jumper wires
- Breadboard (optional)

## Pin Connections
| Component          | Arduino Pin |
|--------------------|-------------|
| Soil Moisture Sensor Signal | A0         |
| OLED Display SDA   | A4         |
| OLED Display SCK   | A5         |
| LED                | 9          |
