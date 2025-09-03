# ESP32_Arduino_Comms
Boilerplate for bidirectional serial communication between an ESP32 and Arduino Uno

Wiring Diagram:

Arduino Uno (5V)          ---------------------> Logic Level Shifter (HV)
Arduino Uno (GND)         ---------------------> Logic Level Shifter (GND on HV side of component)
Arduino Uno (TX - Pin 1)  ---------------------> Logic Level Shifter (HV2)
Arduino Uno (RX - Pin 0)  ---------------------> Logic Level Shifter (HV3)

ESP32 (3.3V)         ----------------------> Logic Level Shifter (LV)
ESP32 (GND)          ----------------------> Logic Level Shifter (GND on LV side of component)
ESP32 (TX - Pin 17)  ----------------------> Logic Level Shifter (LV3)
ESP32 (RX - Pin 16)  ----------------------> Logic Level Shifter (LV2)

ESP32 (GND)  <----------------------> Arduino Uno (GND)