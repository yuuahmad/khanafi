#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int GAS_SENSOR_LOW = A0;
int Buzzer = 6;
int nilaialkohol = 0;

void beep(unsigned char delayms)
{                          //creating function
  analogWrite(Buzzer, 20); //Setting pin to high
  delay(delayms);          //Delaying
  analogWrite(Buzzer, 0);  //Setting pin to LOW
  delay(delayms);          //Delaying
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);

  lcd.init(); // initialize the lcd
  lcd.backlight();
  beep(50); //Beep
  beep(50); //Beep
  lcd.setCursor(0, 0);
  lcd.print("SISTEM DETEKSI");
  lcd.setCursor(0, 1);
  lcd.print("ALKOHOL");
  delay(3000);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("nilai Alkohol :");
  // put your main code here, to run repeatedly:
  nilaialkohol = analogRead(GAS_SENSOR_LOW);
  nilaialkohol = map(nilaialkohol, 410, 510, 0, 100);
  if (nilaialkohol == LOW)
  {
    lcd.setCursor(0, 1);
    lcd.print(nilaialkohol);
    lcd.print(" %   ");
    beep(50); //Beep
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print(nilaialkohol);
    lcd.print(" %   ");
  }
  delay(200);
}
