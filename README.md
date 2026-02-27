### inter-esp32-i2c-communication-blinky
Demonstration of I2C communication protocol using two ESP32 modules, both with in-built button & LEDs.

## ℹ️ Overview
This project demonstrates the use of I2C communication protocol to establish packet transfers between two ESP32 modules. The ESP32 modules used:
1. ESP32-wroom-32: Built in LED (GPIO 2) and button (GPIO 0).
2. ESP32-c6: Built in LED (GPIO 8) and button (GPIO 9).

When buttons are pressed on each of the ESP32s, the LEDs in the attached ESP32 blinks / changes colors.
The code is written in C++ using native libraries (Wire and Arduino) and NeoPixel for the ESP32-c6 since it uses the WS281 LED.
Environment: VsCode + Platformio.

## 📝 Instructions

To upload the code to individual ESP32s, I would recommend making two separate projects.
Changes to files: platformio.ini & main.cpp.
For the ESP32-wroom-32: Upload the code which is present by default (ESP32-WROOM #1).
For the ESP32-c6: Upload the code which is present under the headings ESP32-C6 #2.

## ⚡ Connection guide

The connections are shown as below:
<img width="453" height="954" alt="connections" src="https://github.com/user-attachments/assets/dcb0e760-3390-48e3-b0cd-a57121a30878" />

Any value of resistances above 4.7kΩ can be used, I used the 10kΩ and 1kΩ since those were the only resistances I had at hand.

## 📈 Results

When pressing the button on the ESP32-c6, the LED on the ESP32-wroom should light up and vice versa.
<img width="375" height="431" alt="image" src="https://github.com/user-attachments/assets/5404502b-bfe2-4a52-a5c1-2017cb942e5a" />
<img width="384" height="379" alt="image" src="https://github.com/user-attachments/assets/4386cdbe-f741-4cda-8c18-c8f0cade9ab8" />
<img width="330" height="444" alt="image" src="https://github.com/user-attachments/assets/56dadd20-ca1b-4da6-8d38-a94f3627b56e" />


### ✍️ Author

I'm [Moditya gupta](https://github.com/moditya1517) and I created this project as a practice.
