#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int GAS_SENSOR_LOW = 3;
int Buzzer = 6;

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
  pinMode(GAS_SENSOR_LOW, INPUT_PULLUP);
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
  lcd.print("KONDISI :     ");
  // put your main code here, to run repeatedly:
  int GAS_SENSOR_LOW_READ = digitalRead(GAS_SENSOR_LOW);
  if (GAS_SENSOR_LOW_READ == LOW)
  {
    lcd.setCursor(0, 1);
    lcd.print("ALKOHOL DETEC  ");
    beep(50); //Beep
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("ALKOHOL HILANG ");
  }
  delay(200);
}
