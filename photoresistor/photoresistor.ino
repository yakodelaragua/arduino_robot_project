//Photoresistor
int sensorPin = A1;
int sensorValue = 0;

int sensorPin2 = A2;
int sensorValue2 = 0;

//led
int analogOutPin = 9;
int outputValue = 0;


void setup() {
  Serial.begin(9600); //Abrir puerto serial y poner unidades de señal por segundo, para terminal

}

void loop() {
  //Photoresistor
  sensorValue = analogRead(sensorPin);  //Leer valor
  sensorValue2 = analogRead(sensorPin2);  //Leer valor

  //Led
  outputValue = map(sensorValue, 0, 1023, 255, 0); // Map the analog values 0~1023 to the PWM output 
  analogWrite(analogOutPin, outputValue);

  Serial.println(sensorValue);
  Serial.println(sensorValue2);

  delay(2);

}
