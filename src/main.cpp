#include <Arduino.h>
#include "utils.h"
#include "Measurement.h"
#include "RTD.h"

RTD pt1 = RTD(PT100, THREE_WIRE, 17);
RTD pt2 = RTD(PT100, THREE_WIRE, 18);

void setup()
{
  Serial.begin(115200);
  // printSpiPins();
}

void loop()
{
  Serial.print("temp1 = ");
  Serial.println(pt1.temperature());
  Serial.print("temp2 = ");
  Serial.println(pt2.temperature());
  delay(1000);
}