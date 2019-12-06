#include <Arduino.h>

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

void setup()
{
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  flash(4, 50, 50);
  delay(1000);
}
