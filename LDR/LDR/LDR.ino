const int ldrPin = 2;  // LDR module DO pin connected to digital pin 2

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  pinMode(ldrPin, INPUT);  // Set ldrPin as an input
}

void loop() {
  int ldrValue = digitalRead(ldrPin);  // Read the value from the LDR module
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);  // Print the value to the Serial Monitor
  delay(500);  // Wait for half a second before taking another reading
}
