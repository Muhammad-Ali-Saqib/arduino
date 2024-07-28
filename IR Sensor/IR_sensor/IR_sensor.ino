#include <IRremote.h>

const int RECV_PIN = 11;  // Pin where the IR receiver is connected

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the IR receiver
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("IR Code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print the received value in hexadecimal
    IrReceiver.resume();  // Receive the next value
  }
}
