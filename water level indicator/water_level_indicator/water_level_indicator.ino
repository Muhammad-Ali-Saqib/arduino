#include <LiquidCrystal.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3); // RS, E, D4, D5, D6, D7

const int waterSensorPin = A0; // Pin for water level sensor
const int buzzerPin = 2; // Pin for buzzer
const int threshold = 640; // Water level threshold (adjust as needed)

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Set up the buzzer pin
  pinMode(buzzerPin, OUTPUT);
  // Start with a clear LCD
  lcd.clear();
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(waterSensorPin);
  
  // Display the water level on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
  lcd.setCursor(0, 1);
  lcd.print(waterLevel);

  // Print the water level to the Serial Monitor
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  // Check water level and activate buzzer if necessary
  if (waterLevel > threshold) {
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
  }

  delay(500); // Delay for stability
}
