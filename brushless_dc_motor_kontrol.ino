
 #include<TimerOne.h>
#include <Servo.h>

Servo myservo;  
int sayac1 = 0;
int potpin = 0;  
int val;    

void setup() {
   Serial.begin(9600);
  attachInterrupt(5,say1,FALLING);
  myservo.attach(10);  
  myservo.write(30);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt( timerIsr);
}

void loop() {
  val = analogRead(potpin);           
  val = map(val, 0, 1023, 0, 180);     
  myservo.write(val);                
  
  delay(15);                          
}
void say1()
{
  sayac1=sayac1+1;
}


void timerIsr()
{
  Serial.print(val);
  Serial.print(" ");
  Serial.println(sayac1);

  
  Serial.println(" ");
  sayac1=0;
 
  
}
