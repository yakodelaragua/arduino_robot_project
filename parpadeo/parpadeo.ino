int LED = 9;

void setup() {
  pinMode(LED, OUTPUT); //Inicializar

}


void loop() {
  digitalWrite(LED, HIGH); //Encender led
  delay(1000);
  
  digitalWrite(LED, LOW);
  delay(1000);

}