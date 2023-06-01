#include <LiquidCrystal_I2C.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);

#define tempPin A0
#define smoke A1
float Reading;
float temp;
int smokeValue; 
int red = 12;
int buz=3;

void setup() {
 lcd.begin(16,2);
 lcd.setBacklight(1);
 pinMode(tempPin,INPUT);
 pinMode(red, OUTPUT);
 pinMode(buz, OUTPUT);
}

void loop() {
Reading = analogRead(tempPin); 
temp=Reading/1024;
temp=(temp*5 -0.5)*100; 
lcd.print("TEMP =   ");
lcd.setCursor(8,0);
lcd.print(temp); 
lcd.print("  C");
lcd.setCursor(1,1);
//delay(3000);
  if(temp>=21 && temp<27){
  digitalWrite(red, LOW);
  lcd.print("GOOD WEATHER :)");
}
else if(temp>=27 && temp<=60)
{ 
  lcd.print("        ");
  digitalWrite(red, HIGH);
  lcd.print("FAN ON!");
  lcd.setCursor(0,0);
}
else if(temp>60){
  digitalWrite(red, LOW);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.println(" TEMP TOO HIGH  ");
  delay(500);
  lcd.setCursor(0,1);
  lcd.println(" FIRE  EXPECTED  ");
  delay(500);
  smokeValue = analogRead(smoke);
  while(smokeValue >=30){
     lcd.setCursor(0,1);
     lcd.println("FIRE  DETECTED!");
     tone(3,1000,100);
     delay(10);
     tone(3,1000,100);
     delay(10);
     smokeValue = analogRead(smoke);}
  lcd.setCursor(0,0);
}
else if (temp<21){
  lcd.clear();
  lcd.print("TEMP = ");
  lcd.setCursor(8,0);
  lcd.print(temp); 
  lcd.print(" C");
  lcd.setCursor(3,1);
  digitalWrite(red, HIGH);
  lcd.print("HEATER ON");
  lcd.setCursor(0,0);
}
}
  
  