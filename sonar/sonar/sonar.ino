#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pins for the HC-SR04
const int trigPin = 7;
const int echoPin = 6;

// Variable for storing the duration and distance
long duration;
int distance;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Set the trigPin as an OUTPUT and the echoPin as an INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Print initial message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.0343 / 2; // Speed of sound wave divided by 2 (go and back)

  // Display the distance on the LCD
  lcd.setCursor(0, 1); // Set the cursor to the beginning of the second line
  lcd.print("                "); // Clear the previous value
  lcd.setCursor(0, 1); // Reset the cursor to the beginning of the second line
  lcd.print(distance);
  lcd.print(" cm");

  // Wait for a short time before the next reading
  delay(500);
}
