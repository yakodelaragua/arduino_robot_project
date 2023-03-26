char ble_val;
int LED = 9;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);


}

void loop() {
  if (Serial.available() > 0) { //Si hay datos
    ble_val = Serial.read(); //Leer datos del serial port buffer
    Serial.println("DATA RECEIVED");
    Serial.println(ble_val);
    if(ble_val == 'a') {
      digitalWrite(LED, HIGH);
    }
    if (ble_val == 'b') {
      digitalWrite(LED, LOW);
    }
  }

}
