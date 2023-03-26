int trigPin = 12; // Pin Trig attaches to 12
int echoPin = 13; //Pin Echo attaches to 13
int LED = 9;

long duration, cm, inches;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 

  pinMode(LED, OUTPUT);

  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration / 2) / 29.1; // convertir a cm

  if(cm < 10) {
    digitalWrite(LED, HIGH);      
  } else {
    digitalWrite(LED, LOW);
  }

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(50);
  
}
