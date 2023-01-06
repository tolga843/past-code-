
#include <TimerOne.h>
#include <Servo.h>
#include <Wire.h>
#include <L3G.h>
#include <LPS.h>
#include <LSM303.h>
#include <SPI.h>

 L3G gyro;
 LSM303 compass;
 LPS ps;

 Servo BLDC1;
 Servo BLDC2;

 int sayac1 = 0;
 int sayac2 = 0;
 double pwm1=28;
 double pwm2=28;
 int x;
 int val=0;
 double ekle=1;
 int setDevir1,setDevir2,HataDevir1,saya1,saya2;
 double kp_devir1,pw1
// double pw1;
// pw1=28;

//double x_toplam=0;
//double y_toplam=0;
//double z_toplam=0;


void setup() {

  Serial.begin(9600);
    Timer1.initialize(100000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor

  
  Wire.begin();
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();



attachInterrupt(5,say1,FALLING);
attachInterrupt(4,say2,FALLING);

 BLDC1.attach(9);
 BLDC2.attach(10);

 BLDC1.write(25);
 BLDC2.write(25);
delay(3000);
}
void loop() {
 // kontrolör ayarı yapılır
  double set_up=90;
  double hata=set_up-y_toplam;
  double kp=0.01;
  
gyro.read();
//val=val+ekle;
//  if(val>=190)
//  {val=190;ekle=0;}
//
//  x=val;
      setDevir1=600;
      kp_devir1=0.0001;
//      //Serial.println(sayac1);
//      HataDevir1=setDevir1-saya1;
//      // Serial.println(HataDevir1);
//     // Serial.println(kp_devir1*(double)HataDevir1);
//      pw1=pw1+kp_devir1*(double)HataDevir1;
//      pwm1=(int)pw1;



//      delay(100);
  
}

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
//  Serial.print(pwm1);
  Serial.print("sayac1: ");
  Serial.print(sayac1);
  Serial.print("   ");
//  Serial.print(pwm2);
//  Serial.print("sayac2: "); 
//  Serial.println(sayac2);
//  Serial.println(val);


  //Serial.print("G ");
  //Serial.print("X: ");
  //x_toplam=x_toplam+(double)gyro.g.x;
  y_toplam=(y_toplam+(double)gyro.g.y-41)/100;
  //z_toplam=z_toplam+(double)gyro.g.z;
  //Serial.print((double)x_toplam);
//  Serial.print(" Y: ");
//  Serial.print((double)y_toplam);
 // Serial.print(" Z: ");
  //Serial.println((double)z_toplam);
//  Serial.println(" ");
//  Serial.println(" ");


saya1=sayac1;
saya2=sayac2;
sayac1=0;
sayac2=0;

      HataDevir1=setDevir1-saya1;
      // Serial.println(HataDevir1);
     // Serial.println(kp_devir1*(double)HataDevir1);
      pw1=pw1+kp_devir1*(double)HataDevir1;
      pwm1=(int)pw1;

//        pwm1+=ekle;
////      pwm2+=ekle;
//      if (pwm1==150)
//      {
//      ekle=-ekle;
//        }
//              if (pwm1==26)
//      {
//      ekle=-ekle;
//        }
  Serial.print("pwm1= ");
  Serial.println((int)pwm1);
//    Serial.print("pwm2= ");
//  Serial.println(pwm2);
  
        BLDC1.write(pwm1);
//      BLDC2.write(pwm2);

}
