#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);   // SDA - A4 SCL - A5

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float t, t_, h, h_;

void setup() {
  lcd.begin();
  dht.begin();

	lcd.backlight();

  lcd.print("DHT-22 begin!");

}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (t != t_ && h != h_){
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.setCursor(0, 2);
    lcd.print("Humidity: ");
    lcd.print(h);
    h_ = h;
    t_ = t;
  }
  delay(5000);
}
