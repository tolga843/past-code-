#include<TimerOne.h>

//led durum değişkenleri
boolean durum0 = false;
boolean durum1 = false;


void setup() {
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt( timerIsr);// interrupt fonksiyonu belirtiliyor.
  cli(); // interruptlar durduruluyor.
// timer0 2kHz değerine ayarlanıyor
  TCCR0A = 0; //TCCR0A register 0'lanıyor.
  TCCR0B = 0; //TCCR0B register 0'lanıyor.
  TCNT0 = 0; // sayac değeri 0'la
  // OCRxAkarşılaştırma register ı 2 kHz değer için ayarlanıyor.
  // 16 MHz osilatör, 2 kHz timer0 ın çalışma frekansı, 64 prescaler
  OCR0A = 124; //= (16*10^6)/(2000*64)-1 (değer 256 dan küçük)
  // CTC mod açılıyor.
  TCCR0A |= (1 << WGM01);
  // CS01 CS00 bitleri 64 prescaler için ayarlanıyor.
  TCCR0B |=(1 << CS01) | (1 << CS00);
  // timer karşılaştırma interrupt ı aktifleştiriliyor.
  TIMSK0 |= (1 << OCIE0A);
  // timer1 interrupt 1Hz e kuruluyor.

  
  TCCR1A = 0; // TCCR1A register 0 lanıyor
  TCCR1B = 0;
  TCNT1 = 0;
  // OCRxA karşılaştırma register ı 1 Hz değer için hazırlanıyor.
  // 16 MHz osilatör, ! Hz timer1 in çalışma frekansı, 1024 prescaler.
  OCR1A = 15624; //= (16*10^6)/(1*1024)-1(değer 65536 dan küçük)
  //CTC mod açılıyor.
  TCCR1B |= (1 << WGM12);
  // CS10 CS12 bitleri 1024 prescaler için ayarlanıyor.
  TCCR1B |= (1 << CS12) | (1 << CS10);
// timer karşılaştırma interrupt ı aktifleştiriliyor.
  TIMSK1 | (1 << OCIE1A);
  sei();//interruptlar aktifleştiriliyor.
  

}
// kurulum tamamlandı.

ISR(TIMER0_COMPA_vect){ //timer0 interrupt'ı 2 kHz'de tetikleniyor.

  if(durum0){
    digitalWrite(8, HIGH);
    durum0=0;
  }
  else{
    digitalWrite(8,LOW);
    durum0=1;
  }
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt'ı 1Hz de tetikleniyor.
  if(durum1){
    digitalWrite(13,HIGH);
    durum1 = 0;
  }
  else{
    digitalWrite(13,LOW);
    durum1 = 1;
  }
}


void loop() {
  
      // ana program
}


void timerIsr()
{
  //led lojik durumu tersleniyor.
  digitalWrite(13, !digitalRead(13) );
}
