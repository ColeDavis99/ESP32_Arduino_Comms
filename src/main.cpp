/*
  (This is the code that gets uploaded to the ESP32.)
  
  INTRO:
    - This code is a boilerplate for bi-directional serial communication between an Arduino Uno and an ESP32
    - The ESP32 pings the Arduino every two seconds with "Ping from ESP32"
    - The ESP32 also continuously polls for any messages recieved from the Arduino and prints them to the serial port for debugging
  

  HARDWARE NOTE:
    A) Make sure to use a bi-directional logic level shifter (aka level converter, logic shifter...)
      - This is because the Arduino's logic pins operate at 5v and the ESP32 operates at 3.3v
      - 5v from the Arduino could fry the ESP32
*/

#include <Arduino.h>  //Only required if using VS Code Plugin "PlatformIO" as your IDE.

HardwareSerial mySerial(2); // Use UART2 on pins RX=16, TX=17
unsigned long lastSend = 0;

void setup()
{
  Serial.begin(9600);                       // USB debug to PC
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // Comm with Uno
  Serial.println("ESP32 ready");
}

void loop()
{
  // Send message every 2 seconds
  if (millis() - lastSend > 2000)
  {
    mySerial.println("Ping from ESP32");
    Serial.println("Sent: Ping from ESP32");
    lastSend = millis();
  }

  // Check for incoming data from Uno
  if (mySerial.available())
  {
    String msg = mySerial.readStringUntil('\n');
    Serial.print("Received from Uno: ");
    Serial.println(msg);
  }
}