//Photoresistor
#define light_Pin_L A1
#define light_Pin_R A2
//Motor
#define motor_Direc_L 4
#define motor_PWM_L 6
#define motor_Direc_R 2
#define motor_PWM_R 5

int left_light;
int right_light;

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

  
}
