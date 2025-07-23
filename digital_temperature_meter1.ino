#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // RS, E, D4, D5, D6, D7

int tempPin = A0; // TMP36 connected to A0

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp: ");
}

void loop() {
  int reading = analogRead(tempPin);
  
  // Convert reading to voltage
  float voltage = reading * 5.0 / 1023.0;
  
  // Convert voltage to Celsius
  float temperatureC = (voltage - 0.5) * 100.0;

  lcd.setCursor(6, 0);
  lcd.print(temperatureC);
  lcd.print(" C");

  delay(1000); // update every second
}