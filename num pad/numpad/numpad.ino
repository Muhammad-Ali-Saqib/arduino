//Connect the keypad pins to the Arduino digital pins:
//
//    Row 1 to Arduino pin 9
//    Row 2 to Arduino pin 8
//    Row 3 to Arduino pin 7
//    Row 4 to Arduino pin 6
//    Column 1 to Arduino pin 5
//    Column 2 to Arduino pin 4
//    Column 3 to Arduino pin 3
//    Column 4 to Arduino pin 2

#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}
