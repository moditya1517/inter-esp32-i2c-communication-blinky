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
