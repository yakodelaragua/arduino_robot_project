//Photoresistor
#define light_Pin_L A2
#define light_Pin_R A1

//Motor
#define motor_Direc_L 4
#define motor_PWM_L 6
#define motor_Direc_R 2
#define motor_PWM_R 5

int left_light;
int right_light;

int motor_PWM_LOW = 225;
int motor_PWM_HIGH = 55;

void setup() {
  Serial.begin(9600);
  pinMode(light_Pin_L, INPUT);
  pinMode(light_Pin_R, INPUT);
  
  pinMode(motor_Direc_L, OUTPUT);
  pinMode(motor_PWM_L, OUTPUT);
  pinMode(motor_Direc_R, OUTPUT);
  pinMode(motor_PWM_R, OUTPUT);

}

void loop() {
  left_light = analogRead(light_Pin_L);
  right_light = analogRead(light_Pin_R);
  
  Serial.print("Valor luz izquierda: ");
  Serial.println(left_light);
  Serial.print("Valor luz derecha: ");
  Serial.println(right_light);
  

  if(left_light > 650 && right_light > 650) { //Recto
    Tank_front();
    
  } else if(left_light <= 650 && right_light > 650) { //Izquierda
    Tank_left();

  } else if(left_light > 650 && right_light <= 650) { //Derecha
    Tank_right();

  } else {  //Para
    Tank_stop();
    
  }
  
  
}

void Tank_front() {
  digitalWrite(motor_Direc_L, HIGH);
  analogWrite(motor_PWM_L, motor_PWM_HIGH);
  digitalWrite(motor_Direc_R, HIGH);
  analogWrite(motor_PWM_R, motor_PWM_HIGH);
  
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
