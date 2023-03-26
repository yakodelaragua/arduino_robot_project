#include <IRremote.h>

int RECV_PIN = 3;

int LED = 9;
bool flag = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);
  irrecv.enableIRIn(); //Habilitar recibidor
}

void loop() {
  if (irrecv.decode(&results)) { //decodificado correctamente
    if (results.value == 0xFF02FD & flag == 0) {  //Si se pulsa OK y esta apagado
      digitalWrite(LED, HIGH);
      flag = 1;
    }else if (results.value == 0xFF02FD & flag == 1) {
        digitalWrite(LED, LOW);
      flag = 0;
    }

    
    Serial.println(results.value, HEX); //Coger valor en hexadecimal y escribir codigo
    irrecv.resume(); //Recibir siguiente
  }
  delay(100);
}
