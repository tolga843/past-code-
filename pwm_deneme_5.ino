
 #include<TimerOne.h>
#include <Servo.h>


Servo myservo1; 

int sayac1 = 0;

int pwm1 = 0;
int pot = 0;

void setup() {
  Serial.begin(9600);
 //attachInterrupt(5,say1,FALLING);
  myservo1.attach(10);

  myservo1.write(25);

  delay(3000);
  
  Timer1.initialize(1000000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor


}

void loop() { 
     int pot = analogRead(A0);
  pot = map(pot, 0, 1023, 0, 179);
  myservo1.write(pot);
  
   myservo1.write(pwm1);

  delay(1000);

}
void say1()
{
  sayac1=sayac1+1;
}

 void timerIsr()
{
  Serial.print(pwm1);
  Serial.print("   ");
  Serial.println(sayac1);

  sayac1=0;

}
