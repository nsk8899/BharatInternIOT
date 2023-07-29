// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int buz = 0;

int gas = 0;

int sensorValue = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  lcd_1.begin(16, 2);
  pinMode(8, OUTPUT);
  Serial.begin(9600);

  buz = 8;
  gas = analogRead(A0);
  sensorValue = 0;
  lcd_1.print("Air Quality");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Today");
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.clear();
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
  sensorValue = analogRead(A0);
  lcd_1.print("Air Quality ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("In PPM :");
  lcd_1.print(sensorValue);
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.clear();
  lcd_1.print("Air Quality: ");
  lcd_1.print(sensorValue);
  if (sensorValue >= 650) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  if (sensorValue <= 500) {
    Serial.print("Fresh Air");
    Serial.print("\r\n");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fresh Air");
    delay(1000); // Wait for 1000 millisecond(s)
    lcd_1.clear();
  } else {
    if (sensorValue >= 500 && 1 <= 650) {
      Serial.print("Poor Air");
      Serial.print("\r\n");
      lcd_1.setCursor(0, 1);
      lcd_1.print("Poor Air");
      delay(1000); // Wait for 1000 millisecond(s)
      lcd_1.clear();
    } else {
      if (sensorValue >= 650) {
        Serial.print("Very Poor Air");
        Serial.print("\r\n");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Very Poor Air");
        delay(1000); // Wait for 1000 millisecond(s)
        lcd_1.clear();
      }
    }
  }
}