// C++ code
//
#include <Servo.h>
Servo myservo; 
int pos = 0;

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //purple wires
byte colPins[COLS] = {5, 4, 3,2};  //orange wires
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String passcode= ""; //variable in which password is stored
int count=0;
int i;
int BUZZ = 12;

void setup(){
 Serial.begin(9600);
 Serial.println("");
 Serial.println("***********WELCOME***********");
 Serial.print("Please enter your password:");
 pinMode(11, OUTPUT); //red led
 pinMode(10, OUTPUT); //green led
 pinMode(BUZZ,OUTPUT);
 myservo.attach(13);
 pinMode(A5, OUTPUT); //House led
 }

void loop(){
 myservo.write(0); 
 char key = keypad.getKey(); 
 if (key){
   Serial.print(key);
   count=count+1;
   passcode=passcode+key;
 
   if(count==4){
     if (passcode=="A68*")
      {
       Serial.println("");
       Serial.println("ACCESS GRANTED");
       for(i=0;i<6;i++){  //led blinks 7 times
         digitalWrite(10, HIGH); // set the LED on
         delay(100); // wait for 0.1 second
         digitalWrite(10, LOW);
         delay(100); } 
       for (pos = 0; pos <= 90; pos++) {
         myservo.write(pos); 
         digitalWrite(BUZZ,HIGH);
         delay(15); }
       digitalWrite(BUZZ,LOW);
       delay(1000);
       analogWrite(A5, 255);
       delay(600);
       Serial.println("DOOR OPENED");
       Serial.println("YOU ENTERED THE HOUSE");
       Serial.println("HOUSE LED ON!");
       for (pos = 90; pos >= 0; pos--) { 
         myservo.write(pos); 
         delay(15); }
       exit(0);
      }
     else
      {
       Serial.println("");
       Serial.println("ACCESS DENIED");
       for(i=0;i<3;i++){  //led blinks 4 times
         digitalWrite(11, HIGH); // set the LED on
         tone(BUZZ, 1250, 100);//rings the buzzer
         delay(100); // wait for 0.1 second
         tone(BUZZ, 1250, 200);//rings the buzzer
         delay(200); // wait for 0.25 second
         digitalWrite(11, LOW);
         delay(100); }
       tone(BUZZ, 1250, 600);//rings the buzzer
       delay(600); // wait for 0.6 second
       Serial.print("RE-ENTER PASSWORD:");
       passcode="";
       count=0;
      }
   }
 }

}

