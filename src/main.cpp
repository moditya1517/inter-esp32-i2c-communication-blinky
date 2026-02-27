// Code for the ESP32-WROOM-32 - SLAVE DEVICE
#include <Arduino.h>
#include "Wire.h"

#define I2C_DEV_ADDR 0x55
#define BUTTON_PIN 0
#define LED_PIN 2

uint32_t i = 0;
unsigned long last_t_stamp = millis();

void onRequest()
{
  if (millis() - last_t_stamp < 3000)
  {
    Wire.print(1);
  }
  else
    Wire.print(0);
}

void onReceive(int len)
{
  while (Wire.available())
  {
    char s = (char)Wire.read();
    if (s == '1')
    {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
    }
    else if (s == '0')
      digitalWrite(LED_PIN, LOW);
  }
  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  Serial.setDebugOutput(true);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Wire.onReceive(onReceive);
  Wire.onRequest(onRequest);
  Wire.begin(I2C_DEV_ADDR, 21, 22, 0UL);
}

void loop()
{
  if (!digitalRead(BUTTON_PIN))
  {
    last_t_stamp = millis();
  }
  delay(500);
}

// Code for the ESP32-c6 - MASTER DEVICE
// #include <Arduino.h>
// #include "Wire.h"
// #include <Adafruit_NeoPixel.h>

// #define NUMPIXELS 1 // Number of LEDs
// #define PIN 8
// #define BUTTON_PIN 9

// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// #define I2C_DEV_ADDR 0x55

// uint32_t i = 0, r = 50, g = 0, b = 0;
// int buttonState = 0;

// void setup()
// {
//   pixels.begin();
//   pinMode(BUTTON_PIN, INPUT_PULLUP);

//   Serial.begin(9600);
//   Wire.begin(21, 22, 0UL);
// }

// void loop()
// {
//   buttonState = digitalRead(BUTTON_PIN);
//   if (buttonState == LOW)
//   {
//     Wire.beginTransmission(0x55);
//     Wire.print(1);
//     Wire.endTransmission(true);
//   }
//   else
//   {
//     Wire.beginTransmission(0x55);
//     Wire.print(0);
//     Wire.endTransmission(true);
//   }
//   delay(500);

//   uint8_t bytesReceived = Wire.requestFrom(I2C_DEV_ADDR, 1);

//   if ((bool)bytesReceived)
//   { // If received more than zero bytes
//     uint8_t temp[bytesReceived];
//     Wire.readBytes(temp, bytesReceived);
//     char tt = (char)temp[0];
//     if (tt == '1')
//     {
//       int temp = r;
//       r = g;
//       g = b;
//       b = temp;

//       pixels.setPixelColor(0, pixels.Color(r, g, b));
//       pixels.show();
//       delay(300);
//     }
//     else
//     {
//       pixels.setPixelColor(0, pixels.Color(0, 0, 0));
//       pixels.show();
//       delay(300);
//     }
//   }
// }