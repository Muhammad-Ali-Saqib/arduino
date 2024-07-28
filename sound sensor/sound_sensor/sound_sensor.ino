const int soundSensorPin = A0; // Pin where the sound sensor is connected
int soundLevel;

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  pinMode(soundSensorPin, INPUT); // Set the sound sensor pin as an input
}

void loop() {
  soundLevel = analogRead(soundSensorPin); // Read the sound level
  Serial.print("Sound Level: ");
  Serial.println(soundLevel); // Print the sound level to the Serial Monitor
  delay(100); // Wait for 100 milliseconds before the next reading
}
