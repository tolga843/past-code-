#include <math.h>
 #include<TimerOne.h>
#include <Servo.h>


Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4;

int sayac1 = 0;
int sayac2 = 0;
int sayac3 = 0;
int sayac4 = 0;
//float voltaj=0;
int pwm1,pwm2,pwm3,pwm4;
int x;
int val=30;
float voltaj=0;  
int ekle=1;

void setup() {
  Serial.begin(9600);
  attachInterrupt(5,say1,FALLING);
  attachInterrupt(4,say2,FALLING);
  attachInterrupt(3,say3,FALLING);
  attachInterrupt(2,say4,FALLING);
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);
  
  myservo1.write(25);
  myservo2.write(25);
  myservo3.write(25);
  myservo4.write(25);
  delay(3000);
  
  Timer1.initialize(1000000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor
 

}

void loop() { 
      voltaj=analogRead(A1);
voltaj=3*voltaj*5.045/1023;

val=val+ekle;
  if(val>=190)
  {val=190;ekle=0;}

  x=val;
  

pwm1 =  (2.8562*pow(10,-7)*pow(x,4)) - (9.1713*pow(10,-5)*pow(x,3)) + (0.0095*pow(x,2)) - (0.2355*x) + (33.5973);

pwm2 =  3.5493*pow(10,-7)*pow(x,4) - 1.1509*pow(10,-4)*pow(x,3) + 0.0123*pow(x,2) - (0.3541*x) + (33.3447);

pwm3 =  3.6734*pow(10,-7)*pow(x,4) - 1.1663*pow(10,-4)*pow(x,3) + 0.0123*pow(x,2) - (0.3508*x) + (33.3883);

pwm4 =  3.3714*pow(10,-7)*pow(x,4) - 1.0280*pow(10,-4)*pow(x,3) + 0.0104*pow(x,2) - (0.2576*x) + (33.4171);

   myservo1.write(pwm1);
  myservo2.write(pwm2);
  myservo3.write(pwm3);
  myservo4.write(pwm4);  

  delay(1000);

}
void say1()
{
  sayac1=sayac1+1;
}
void say2()
{
  sayac2=sayac2+1;  
}
void say3()
{
  sayac3=sayac3+1;
  
}
void say4()
{
  sayac4=sayac4+1;
  
}

void timerIsr()
{
  //Serial.println(pwm1);
  //Serial.print("   ");
  Serial.println(sayac1);
    //Serial.println(pwm2);
  //Serial.print("   ");
  Serial.println(sayac2);
    //Serial.println(pwm3);
  //Serial.print("   ");
  Serial.println(sayac3);
    //Serial.println(pwm4);
  //Serial.print("   ");
  Serial.println(sayac4);
  //Serial.println(" ");
  Serial.println(x);
 Serial.println(voltaj);
 //Serial.println(" ");
 //Serial.println(" ");
 
  sayac1=0;
  sayac2=0;
  sayac3=0;
  sayac4=0;


}
