/*
  (This is the code that gets uploaded to the Arduino Uno.)

  INTRO:
    - This code is a boilerplate for bi-directional serial communication between an Arduino Uno and an ESP32
    - The Arduino sends an incrementing counter every 1 second to the ESP32
    - The Arduino also continuously polls for any messages recieved from the ESP32 and prints them to the serial port for debugging

  SOFTWARE NOTE:
    A) You will not be able to upload this sketch to the Arduino while the RX and TX pins are connected to the logic level shifter.
      - The UNO only has one serial channel and can not simultaneously have a sketch uploaded to it and be connected to the ESP32

  HARDWARE NOTE:
    B) Make sure to use a bi-directional logic level shifter (aka level converter, logic shifter...)
      - This is because the Arduino's logic pins operate at 5v and the ESP32 operates at 3.3v
      - 5v from the Arduino could fry the ESP32
    C) Make sure there is a common GND between ESP32 and Arduino (Just tie the GND pins directly to eachother is the easiest way)
      - This ensures stable communication between them as they both agree on their GND reference voltage 
*/

int counter = 0;

void setup() {
  Serial.begin(9600);   // Pins 0 (RX) and 1 (TX) go to logic level shifter, and from there to the ESP32
}

void loop() {
  // Send message to ESP32
  Serial.print("Counter: ");
  Serial.println(counter++);

  // Check for incoming messages from ESP32
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    // Echo back what was received
    Serial.print("Echo from Uno: ");
    Serial.println(msg);
  }

  delay(1000);
}
