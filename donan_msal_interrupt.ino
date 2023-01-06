   
 
 
#include <Servo.h>

Servo myservo1; 

int pot = 0;

void setup() {

  Serial.begin(9600);



  myservo1.attach(10);

}

void loop() {

  int pot = analogRead(A0);
  pot = map(pot, 0, 1023, 0, 179);
  myservo1.write(pot);
  

  
}

  
