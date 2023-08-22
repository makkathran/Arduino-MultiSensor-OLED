# Arduino Sensor System with OLED Display

## 1. Objective
This Arduino code represents a sensor system capable of measuring ambient light, humidity, temperature, and soil moisture. The results are displayed on a 0.96" OLED screen and the serial monitor.

## 2. Components Used
- DHT11 humidity and temperature sensor
- Ambient light sensor
- 0.96" OLED display with SSD1306/SSD1315 driver
- LED
- Soil moisture sensor

## 3. Libraries
- `DHT.h`: Library for handling DHT sensors.
- `Wire.h`: Library for I2C communication.
- `Adafruit_GFX.h` and `Adafruit_SSD1306.h`: Libraries for OLED display management.

## 4. Definitions and Variables
- `DHT_PIN`: Digital pin for DHT sensor.
- `DHT_TYPE`: Type of DHT sensor used (DHT11 in this case).
- `LIGHTSENSORPIN`: Pin definition for the light sensor.
- `LEDPIN`: Output pin definition for the LED.
- `SOILMOISTUREPIN`: Pin definition for the soil moisture sensor.

## 5. Setup Function
- Initializes sensors and display.
- Sets up I2C communication with the display.
- Clears the display content upon initial power-up.

## 6. Loop Function
- Reads the light sensor value.
- Reads the soil moisture sensor value.
- Turns the LED on or off based on light intensity.
- Reads humidity and temperature from the DHT sensor.
- Displays values on the OLED display.
- Prints values to the serial monitor.
