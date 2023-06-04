// The programe to turn on the realay for a short amount of time and them turn it off.


// initializations
int relay_pin = 3;
int on_off_delay = 5000;


// Main function
void setup() {
  
  // setting the relay pin for output
  pinMode(relay_pin, OUTPUT);  
}



// iteration
void loop() {
  digitalWrite(relay_pin, LOW);
  delay(on_off_delay);

  digitalWrite(relay_pin, HIGH);
  delay(on_off_delay);

}
