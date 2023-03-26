#include <Servo.h>

#define servoPin 10

//Motor
#define motor_Direc_L 4
#define motor_PWM_L 6
#define motor_Direc_R 2
#define motor_PWM_R 5

#define Trig 12
#define Echo 13

int front_distance, left_distance, right_distance;
Servo myservo;

int motor_PWM_LOW = 225;
int motor_PWM_HIGH = 55;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(motor_Direc_L, OUTPUT);
  pinMode(motor_PWM_L, OUTPUT);
  pinMode(motor_Direc_R, OUTPUT);
  pinMode(motor_PWM_R, OUTPUT);
  
  myservo.attach(servoPin);
  setServoAngle(90);

  delay(500);

}

void loop() {
  front_distance = checkDistance();

  if(front_distance < 20) {
    Tank_stop();
    delay(500);
    
    setServoAngle(180);
    delay(500);    
    left_distance = checkDistance();
    delay(100);
    
    setServoAngle(0);
    delay(500);
    right_distance = checkDistance();
    delay(100);
    setServoAngle(90);
    delay(500);

    if(left_distance > right_distance) {
      Tank_left();
      delay(700);

    } else {
      Tank_right();
      delay(700);
      
    }

  } else {
    Tank_front();
        
  }  

}


void setServoAngle(byte angle) {
  myservo.write(angle + 10);

}

float checkDistance() {
  static float distance;
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);  
  digitalWrite(Trig, LOW);
  distance = pulseIn(Echo, HIGH) / 58.2;
  delay(10);
  
  return distance;

}

void Tank_front() {
  digitalWrite(motor_Direc_L, HIGH);
  analogWrite(motor_PWM_L, motor_PWM_HIGH);
  digitalWrite(motor_Direc_R, HIGH);
  analogWrite(motor_PWM_R, motor_PWM_HIGH);
  
}

void Tank_back() {
  digitalWrite(motor_Direc_L, LOW);
  analogWrite(motor_PWM_L, motor_PWM_LOW);
  digitalWrite(motor_Direc_R, LOW);
  analogWrite(motor_PWM_R, motor_PWM_LOW);
  
}

void Tank_left() {
  digitalWrite(motor_Direc_L, LOW);
  analogWrite(motor_PWM_L, motor_PWM_LOW);
  digitalWrite(motor_Direc_R, HIGH);
  analogWrite(motor_PWM_R, motor_PWM_HIGH);
  
}

void Tank_right() {
  digitalWrite(motor_Direc_L, HIGH);
  analogWrite(motor_PWM_L, motor_PWM_HIGH);
  digitalWrite(motor_Direc_R, LOW);
  analogWrite(motor_PWM_R, motor_PWM_LOW);
  
}

void Tank_stop() {
  digitalWrite(motor_Direc_L, LOW);
  analogWrite(motor_PWM_L, 0);
  digitalWrite(motor_Direc_R, LOW);
  analogWrite(motor_PWM_R, 0);
  
}