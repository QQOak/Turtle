#include <Arduino.h>
#include <Bounce2.h>

#define Power_Button 2
#define L1_Button 3
#define L2_Button 4
#define L3_Button 5

Bounce PowerButton = Bounce();
Bounce L1Button = Bounce();
Bounce L2Button = Bounce();
Bounce L3Button = Bounce();

unsigned long previousMillis = 0;
unsigned long interval = 1000;

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
}

void AttachButtons()
{
  pinMode(Power_Button, INPUT_PULLUP);
  PowerButton.attach(Power_Button);
  PowerButton.interval(5);
  
  pinMode(L1_Button, INPUT_PULLUP);
  L1Button.attach(L1_Button);
  L1Button.interval(5);

  pinMode(L2_Button, INPUT_PULLUP);
  L2Button.attach(L2_Button);
  L2Button.interval(5);

  pinMode(L3_Button, INPUT_PULLUP);
  L3Button.attach(L3_Button);
  L3Button.interval(5);
}

void UpdateButtons()
{
  PowerButton.update();
  L1Button.update();
  L2Button.update();
  L3Button.update();
}

void setup()
{
  AttachButtons();

  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  processLed();
  UpdateButtons();

  if(PowerButton.fell())
  {
    Serial.println("Power Button Pressed");
  }

  if(L1Button.fell())
  {
    Serial.println("L1 Button Pressed");
  }

  if(L2Button.fell())
  {
    Serial.println("L2 Button Pressed");
  }

  if(L3Button.fell())
  {
    Serial.println("L3 Button Pressed");
  }



  // flash(4, 50, 50);
  // delay(1000);
}


