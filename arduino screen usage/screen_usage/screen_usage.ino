#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // Print the first message on the upper line
  lcd.clear();
  lcd.setCursor(0, 0); // Set the cursor to column 0, row 0 (upper line)
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1); // Set the cursor to column 0, row 1 (lower line)
  lcd.print("Line 2 Message");
  delay(2000); // Wait for 2 seconds

  // Print the second message on the upper line
  lcd.clear();
  lcd.setCursor(0, 0); // Set the cursor to column 0, row 0 (upper line)
  lcd.print("Arduino Rocks!");
  lcd.setCursor(0, 1); // Set the cursor to column 0, row 1 (lower line)
  lcd.print("Line 2 Rocks!");
  delay(2000); // Wait for 2 seconds

  // Print the third message on the upper line
  lcd.clear();
  lcd.setCursor(0, 0); // Set the cursor to column 0, row 0 (upper line)
  lcd.print("How are you?");
  lcd.setCursor(0, 1); // Set the cursor to column 0, row 1 (lower line)
  lcd.print("I'm good!");
  delay(2000); // Wait for 2 seconds
}
