// C++ code
//
#define ldr A0
#define led1 3
#define led3 5
int resistance;
int ledBrightness=0; 
int threshold=400;

void setup(){ 
 Serial.begin(9600);
 pinMode(led1,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(ldr,INPUT);   
}
void loop(){
 resistance= analogRead(ldr);
 Serial.print("RESISTANCE : ");
 Serial.println(resistance);
 delay(1000);
 if(resistance<threshold){
   ledBrightness = map(resistance, 6, 508, 0, 128);
   analogWrite(led1,ledBrightness);
   analogWrite(led3,ledBrightness);}
  else{
   ledBrightness = map(resistance, 508, 1023, 128, 255);
   analogWrite(led1,ledBrightness);
   analogWrite(led3,ledBrightness);}
}

