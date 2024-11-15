#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
//SDA - A4
//SCK - A5

const int sensorPin = A5; // Define analog pin for the soil moisture sensor
const int ledPin = 9; // Define pin for the LED
const int threshold = 500; // Define threshold moisture value

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read sensor value
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  display.clearDisplay();
  display.setTextSize(1);     
  display.setTextColor(WHITE); 
  display.setCursor(0,0);      
  display.print("Moisture: ");
  display.println(sensorValue);
  display.display();

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    display.setCursor(0, 20); 
    display.print("Status: DRY");
  } 
  else {
    digitalWrite(ledPin, LOW); // Turn off LED
    display.setCursor(0, 20);
    display.print("Status: WET");
  }

  display.display();                       

  delay(500); // Wait for 0.5 second
}