void setup() {
  pinMode(12, OUTPUT); // Initialize digital pin 13 as an output
  Serial.begin(9600);  // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming byte

    if (command == 'H') {
      digitalWrite(12, HIGH); // Turn the LED on
    } else if (command == 'L') {
      digitalWrite(12, LOW); // Turn the LED off
    }
  }
}
