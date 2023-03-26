#include <Servo.h>

#define servoPin 10

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(servoPin);

}

void loop() {

  
  for (pos = 0; pos <= 180; pos++) { // From 1°to 180° // in steps of 1 degree
    myservo.write(pos); 
    delay(15);
  }
  for (pos = 180; pos >= 0; pos--) { 
    myservo.write(pos); 
    delay(15);
  }
}


