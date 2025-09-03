# ESP32 ↔ Arduino Uno Communication

Boilerplate for **bidirectional serial communication** between an **ESP32** and **Arduino Uno**.

---

## 🔌 Wiring Diagram

### Arduino Uno → Logic Level Shifter (HV side)
- **Arduino Uno (5V)** → **HV**
- **Arduino Uno (GND)** → **GND (HV side)**
- **Arduino Uno (TX – Pin 1)** → **HV2**
- **Arduino Uno (RX – Pin 0)** → **HV3**

### ESP32 → Logic Level Shifter (LV side)
- **ESP32 (3.3V)** → **LV**
- **ESP32 (GND)** → **GND (LV side)**
- **ESP32 (TX – Pin 17)** → **LV3**
- **ESP32 (RX – Pin 16)** → **LV2**

### Shared Ground
- **ESP32 (GND)** ↔ **Arduino Uno (GND)**
