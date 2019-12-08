#include <Arduino.h>
#include "Control.h"


unsigned long previousMillis = 0;
unsigned long interval = 1000;

Control control = Control();

void flash(int numberOfFlashes, int onTime, int offTime)
{
  Serial.write("Flashing");
  for (int i = 0; i < numberOfFlashes; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(onTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(offTime);
  }
}

void processLed()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  int f;
  auto d = 2.6;
  f = d*2;
  Serial.println(f);
}





void setup()
{
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
  control.AttachButtons(); 
}

void loop()
{
  control.UpdateButtons();

  if (control.PowerButtonPressed()) {
    Serial.println("Change brightness");
  }
  
  if (control.L1ButtonPressed()) {
    Serial.println("Change Pattern");
  }

  if (control.L2ButtonPressed()) {
    Serial.println("Change Speed");
  }

  if (control.L3ButtonPressed()) {
    Serial.println("Change Colours");
  }

  processLed();
}
