int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);

}

void loop () {
  for (int value = 0; value < 255; value = value + 1) {
    analogWrite (LED, value); // LED ON
    delay (5); //delay in 5ms
  }
  for (int value = 255; value > 0; value = value - 1) {
    analogWrite (LED, value);
    delay (5); 
  }
}