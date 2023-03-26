#define L_pin 11 //izquierda
#define M_pin 7 //centro 
#define R_pin 8 //derecha

#define LED 9

void setup() {
  Serial.begin(9600);
  //Poner todos los pins como INPUT
  pinMode(L_pin, INPUT);
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  
}

void loop() {
  //Leer valores de sensores
  int L_val = digitalRead(L_pin);
  int M_val = digitalRead(M_pin);
  int R_val = digitalRead(R_pin);

  Serial.print(L_val);
  Serial.print(" ");
  Serial.print(M_val);
  Serial.print(" ");
  Serial.print(R_val);
  Serial.println(" ");  

  delay(100);

  if (L_val == 0 || M_val == 0 || R_val == 0) {
   digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
