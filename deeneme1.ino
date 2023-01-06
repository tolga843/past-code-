
#include <math.h>
#include<TimerOne.h>
#include <Servo.h>
#include <Wire.h>
#include <L3G.h>
#include <LPS.h>
#include <LSM303.h>
#include <SPI.h>

L3G gyro;
LSM303 compass;
LPS ps;

double x_toplam=0;
double y_toplam=0;
double z_toplam=0;

void timerIsr()
{
   
  //Serial.print("G ");
  //Serial.print("X: ");
  //x_toplam=x_toplam+(double)gyro.g.x;
  y_toplam=(y_toplam+(double)gyro.g.y-41)/100;
  //z_toplam=z_toplam+(double)gyro.g.z;
  //Serial.print((double)x_toplam);
  Serial.print(" Y: ");
  Serial.print((double)y_toplam);
 // Serial.print(" Z: ");
  //Serial.println((double)z_toplam);
   Serial.println(" ");
 Serial.println(" ");
}

void setup() {
  Serial.begin(115200);
    Timer1.initialize(8000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor

  Wire.begin();
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();

}

void loop() {
  // kontrolör ayarı yapılır
  double set_up=15;
  double hata=set_up-y_toplam;
  double kp=0.1;
  
gyro.read();
}
