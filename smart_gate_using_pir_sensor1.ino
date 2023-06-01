// C++ code
//
#include <Servo.h>
Servo myservo; 
int pos = 0; 
int pirPin = 13; 
int pirValue; 
int motionDetected = 0;
int led=11;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT); 
  myservo.attach(12); 
  myservo.write(pos);
  pinMode(led, OUTPUT);
}

void loop()
{
  pirValue = digitalRead(pirPin);
  Serial.println(pirValue); 
  if(pirValue == 1) {
   motionDetected = 1;
  }
  else 
   {     if(pos!=0){
         Serial.println("3");
         for (pos = 90; pos >= 0; pos--) { //closing the door
           myservo.write(pos); 
           delay(15); }}
         pos=0;
   }
  while(motionDetected == 1) {
    if(pos==0){
       Serial.println("1");
       for (pos = 0; pos <= 90; pos++) {  //opening the door
         myservo.write(pos); 
         delay(15);  }
       digitalWrite(led,HIGH);
       }
    else{ 
      Serial.println("2");
       myservo.write(90);
      motionDetected = 0;
      }  
} 
}
