//Connections:
//
//    Joystick:
//        VRx to A0
//        VRy to A1
//        SW (button) to a digital pin, e.g., 7
//        VCC to 5V
//        GND to GND
//    Servo Motor:
//        Signal pin to 9
//        VCC to 5V
//        GND to GND
//


#include <Servo.h>

Servo myServo;

const int joystickXPin = A0;  // Joystick X-axis
const int joystickYPin = A1;  // Joystick Y-axis
const int joystickBtnPin = 7; // Joystick button
const int servoPin = 9;       // Servo pin

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  
  pinMode(joystickBtnPin, INPUT_PULLUP);

  Serial.println("Joystick and Servo Control");
}

void loop() {
  int joystickXVal = analogRead(joystickXPin);
  int joystickYVal = analogRead(joystickYPin);
  int joystickBtnState = digitalRead(joystickBtnPin);

  // Map joystick value to servo angle (0-180 degrees)
  int servoAngle = map(joystickXVal, 0, 1023, 0, 180);
  myServo.write(servoAngle);

  // Display values in serial monitor
  Serial.print("Joystick X: ");
  Serial.print(joystickXVal);
  Serial.print(" | Joystick Y: ");
  Serial.print(joystickYVal);
  Serial.print(" | Button: ");
  Serial.print(joystickBtnState == LOW ? "Pressed" : "Not Pressed");
  Serial.print(" | Servo Angle: ");
  Serial.println(servoAngle);

  delay(100); // Add a small delay to make the serial monitor more readable
}
