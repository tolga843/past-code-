 #include <UM7.h>
#include <Servo.h>
//#include<TimerOne.h>

//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM7 imu;
Servo motor1;
Servo motor2;

int pin_motor1=8;
int pin_motor2=9;
int period=100;
long zaman=0,P,I,D,PID_total;
double pitch;
double pitch_set=0;
double pitch_hata;
double kp=-0.05;
double kd=-0.005;
double pwm1=0;
double pwm2=0;
long int zaman_araligi=100000;//mikro saniye olarak zaman aralığı
double pitch_hata_onceki=0;
double pitch_hata_turevi=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
//  Timer1.initialize(zaman_araligi);
//   Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor.
   motor1.attach(8);
   motor2.attach(9);
cli();
   for(int i=0;i<=70;i++)
   {
    pwm1=i;
    pwm2=i;
    motor1.write(pwm1);
    motor2.write(pwm2);
  Serial.print("pwm1: ");
  Serial.println(pwm1);
  Serial.print("pwm2: ");
  Serial.println(pwm2);
  Serial.println(" ");
    delay(500);
    }
    sei();
}
 
void loop() {
 
  if(millis()>zaman+period)
  {
    zaman = millis();
    pitch_hata=pitch_set-pitch;
    pitch_hata_turevi = pitch_hata-pitch_hata_onceki;
    pitch_hata_onceki = pitch_hata;
    P=kp*pitch_hata;
    D=kd*(pitch_hata_turevi/period);
//    I=I+ki*(pitch_hata*period);
    PID_total=P+D;
    pwm1=PID_total;
    pwmsinir(pwm1);
    motor1.write((int)pwm1);
  }
  
  
  
  
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {
    if (imu.encode(Serial1.read())) {  // Reads byte from buffer.  Valid packet returns true.
      pitch=imu.pitch/91.02222;
//      Serial.print("pitch: ");
//      Serial.println(pitch);
//      Serial.println(" ");
//      Serial.print("roll: ");
//      Serial.println(imu.roll/91.02222);
//      Serial.print("yaw: ");
//      Serial.println(imu.yaw/91.02222);
//      Serial.println(" ");

  
//  delay(100);
    }
  //kontrolör yazılımı başlar
  //kontrolör yazılımı başlar
  //pitch_hata=pitch_set-pitch;
  //Serial.print("pitch_hata: ");
//  Serial.println(pitch_hata);
//  pwm1=pwm1+kp*pitch_hata;
//  pwm2=pwm2-kp*pitch_hata;
//  motor1.write(pwm1);
//  motor2.write(pwm2);
  }
  //delay(100);


  //delay(100);
  
}

double pwmsinir(double deger)
{
  if(deger<50)
  return 50;
  
  else if(deger>90)
  return 90;
  else
  return deger;
  
  }
//  void timerIsr()
//{
//  pitch_hata=pitch_set-pitch;
//  pitch_hata_turevi=1000000*(pitch_hata-pitch_hata_onceki)/zaman_araligi;
//  Serial.print("pitch: ");
//  Serial.println(pitch);
//  Serial.print("pitch_hata: ");
//  Serial.println(pitch_hata);
//  Serial.print("pitch_hata_turvi: ");
//  Serial.println(pitch_hata_turevi);
//  pwm1=pwm1+kp*pitch_hata+kd*pitch_hata_turevi;
//  pwm2=pwm2-kp*pitch_hata-kd*pitch_hata_turevi;
//  Serial.println(pwm1);
//  Serial.println(pwm2);
//  pwm1=pwmsinir(pwm1);
//  pwm2=pwmsinir(pwm2);
//  motor1.write((int)pwm1);
//  motor2.write((int)pwm2);
//  Serial.print("pwm1: ");
//  Serial.println(pwm1);
//  Serial.print("pwm2: ");
//  Serial.println(pwm2);
//  Serial.println(" ");
//}
