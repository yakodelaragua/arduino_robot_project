#include <IRremote.h>

#define ML_Ctrl 4
#define ML_PWM 6
#define MR_Ctrl 2
#define MR_PWM 5

int RECV_PIN = 3;

int LED = 9;
bool flag = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

byte speeds_L = 200; //the initial speed of the left motor is 200
byte speeds_R = 200; //the initial speed of the right motor is 200


void setup() {
  irrecv.enableIRIn(); //Habilitar recibidor
  Serial.begin(9600); 
  //pinMode(LED, OUTPUT);
  
  pinMode(ML_Ctrl, OUTPUT); //Control direccion motor izquierdo
  pinMode(ML_PWM, OUTPUT); //PWM control izquierdo
  pinMode(MR_Ctrl, OUTPUT);//Control direccion motor derecho
  pinMode(MR_PWM, OUTPUT); //PWM control derecho
}

void loop() {
    if (irrecv.decode(&results)) { //decodificado correctamente
      if (results.value == 0xFF02FD & flag == 0) {  //Si se pulsa OK y esta apagado
        //digitalWrite(LED, HIGH);
        flag = 1;
      } else if (results.value == 0xFF02FD & flag == 1) {
          //digitalWrite(LED, LOW);
        flag = 0;
      }


      if (results.value == 0xFF629D) {  //Arriba
        //front
        digitalWrite(ML_Ctrl, HIGH); //Set direction control speed of the left motor to HIGH
        analogWrite(ML_PWM, 55); //PWM control speed of the left motor is 200
        digitalWrite(MR_Ctrl, HIGH); //Set direction control speed of the right motor to HIGH
        analogWrite(MR_PWM, 55); //PWM control speed of the right motor is 200
        
      }
    
      if (results.value == 0xFFA857) {  //Abajo
        digitalWrite(ML_Ctrl, LOW); //Set direction control speed of the left motor to LOW
        analogWrite(ML_PWM, 225); //PWM control speed of the left motor is 200
        digitalWrite(MR_Ctrl, LOW); //Set direction control speed of the right motor to LOW
        analogWrite(MR_PWM, 225); //PWM control speed of the right motor is 200
      }

        
      if (results.value == 0xFF22DD) {  //Izquierda
        digitalWrite(ML_Ctrl, LOW); //Set direction control speed of the left motor to LOW
        analogWrite(ML_PWM, 225); //PWM control speed of the left motor is 200
        digitalWrite(MR_Ctrl, HIGH); //Set direction control speed of the right motor to HIGH
        analogWrite(MR_PWM, 55); //PWM control speed of the right motor is 200
      }

        
      if (results.value == 0xFFC23D) {  //Derecha
        digitalWrite(ML_Ctrl, HIGH); //Set direction control speed of the left motor to HIGH
        analogWrite(ML_PWM, 55); //PWM control speed of the left motor is 200
        digitalWrite(MR_Ctrl, LOW); //Set direction control speed of the right motor to LOW
        analogWrite(MR_PWM, 225); //PWM control speed of the right motor is 200
      }

      if (results.value == 0xFF6897) {  //Si se pulsa OK y esta apagado
        digitalWrite(MR_Ctrl, LOW);
        analogWrite(MR_PWM, 0);
        digitalWrite(ML_Ctrl, LOW);
        analogWrite(ML_PWM, 0);
      }
      
      //delay(2000);
      
      
      Serial.println(results.value, HEX); //Coger valor en hexadecimal y escribir codigo
      irrecv.resume(); //Recibir siguiente
  }

}
