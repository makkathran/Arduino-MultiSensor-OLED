#include "DHT.h"
#include <Wire.h>  // Include Wire library for I2C
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LIGHTSENSORPIN A0
#define LEDPIN A1
#define SOILMOISTUREPIN A2  // Talajnedvesség érzékelő tüske

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(LIGHTSENSORPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(SOILMOISTUREPIN, INPUT);  // Beállítja a talajnedvesség érzékelőt bemenetként
  Serial.begin(9600);
  dht.begin();

  // Inicializálja az OLED kijelzőt
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  float reading = analogRead(LIGHTSENSORPIN);
  float soilMoisture = analogRead(SOILMOISTUREPIN);  // Olvassa el a talajnedvesség értékét

  if (reading < 200) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(2000);

  float humi = dht.readHumidity();
  float tempC = dht.readTemperature();

  // Megjeleníti az OLED kijelzőn
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Light Level: ");
  display.print(reading);
  display.print(" lux");
  display.setCursor(0, 10);
  display.print("Humidity: ");
  display.print(humi);
  display.print("%");
  display.setCursor(0, 20);
  display.print("Temperature: ");
  display.print(tempC);
  display.print("°C");
  display.setCursor(0, 30);
  display.print("Soil Moisture: ");
  display.print(soilMoisture);  // Megjeleníti a talajnedvesség értékét
  display.display();

  // Ugyancsak kiírja a soros monitoron
  Serial.print("Light Level: ");
  Serial.print(reading);
  Serial.print(" lux");
  Serial.print("  |  ");
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print("%");
  Serial.print("  |  "); 
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.print("  |  "); 
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisture);
  Serial.println();
}
