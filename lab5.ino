#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x3F,20,4);

#include "DHT.h"
#define DHTPIN 2
DHT dht(DHTPIN, DHT22);


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  lcd.setCursor(0,0);
  lcd.print("Silchenko V.A.");
  lcd.setCursor(0,1);
  lcd.print("5023");
  lcd.setCursor(0,2);
  lcd.print("Temperature:      C");
  lcd.setCursor(0,3);
  lcd.print("Humidity:      %");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(12,2);
  lcd.print(t);
  lcd.setCursor(9,3);
  lcd.print(h);
  delay(1000);
}
