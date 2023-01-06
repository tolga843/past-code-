
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
 double kp_devir1,pw1;

 double x_toplam=0;
double y_toplam=0;
double z_toplam=0;

void setup() {

   cli(); //interruptlar durduruluyor.

   //timer0 2kHz degerine ayarlanıyor.
   TCCR0A = 0; //TCCR0A register 0'lanıyor
   TCCR0B = 0; //TCCR0B register 0'lanıyor
   TCNT0 = 0; //sayac değeri 0'la

   //0CRxA karşılaştırma register'ı 2kHz değer için ayarlanıyor.
   //16 MHz osilatör, 2kHz timer0'ın çalışma frekansı, 64 prescalar
   OCR0A = 124; //=(16*10^6)/(2000*64)-1 (değer 256 dan küçük)
   // CTC mod açılıyor.
   TCCR0A |= (1 << WGM01);
   // CS01 ve CS00 bitleri 64 prescalar için ayarlanıyor.
   TCCR0B |= (1 << CS01) | (1 << CS00);
   //timer karşılaştırma interruptı aktifleştiriliyor.
   TIMSK0 |= (1 << OCIE0A);

   // timer1 interrupt 1Hz e kuruyor
   TCCR1A = 0; // TCCR1A register 0'lanıyor.
   TCCR1B = 0;
   TCNT1 = 0;
   // OCRxA karşılaştırma register'ı 1 Hz değer için ayarlanıyor.
   // 16 MHz osilatör, 1 Hz timer1'in çalışma frekansı, 1024 prescalar
   OCR1A = 15624; //= (16*10^6) / (1*1024) - 1 (değer 65536 dan küçük)
   // CTC mod açılıyor.
   TCCR1B |= (1 << WGM12);
   // CS10 ve CS12 bitleri 1024 prescaler için ayarlanıyor.
   TCCR1B |= (1 << CS12) | (1) 
   
}

void loop() {


}
