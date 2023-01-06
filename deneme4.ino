
#include <TimerOne.h>
#include <Servo.h>
#include <Wire.h>


 int sayac1 = 0;
 int sayac2 = 0;

 Servo BLDC1;
 Servo BLDC2;


int pwm1=0;


void setup() {

  Serial.begin(9600);
    Timer1.initialize(1000000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor
  attachInterrupt(5,say1,FALLING);
attachInterrupt(4,say2,FALLING);
 BLDC1.attach(9);
 BLDC2.attach(10);

 BLDC1.write(25);
 BLDC2.write(25);
delay(3000);
}
void loop() {


if (pwm1>=60)
pwm1=60;
else
pwm1++;
BLDC1.write(pwm1);
BLDC2.write(pwm1);
     delay(100);
     Serial.println(pwm1);


void say1()
{
  sayac1=sayac1+1;
  //Serial.println("say1 calisti");
}
void say2()
{
  sayac2=sayac2+1;  
}
void timerIsr()
{
   
sayac1=sayac1*60;
sayac2=sayac2;

  Serial.print("sayac1: ");
  Serial.print(sayac1);
  Serial.print("   ");
//  Serial.print(pwm2);
  Serial.print("sayac2: "); 
  Serial.println(sayac2);
//  Serial.println(val);



sayac1=0;
sayac2=0;





}
