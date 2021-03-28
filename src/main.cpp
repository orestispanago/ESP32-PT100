#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MAX31865.h>
#include <SPI.h>

// Use software SPI: CS, DI, DO, CLK
// Adafruit_MAX31865 maxe = Adafruit_MAX31865(15, 18, 4, 5); // As marked on board

// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 maxe = Adafruit_MAX31865(15); // As marked on board
// Use print_spi_pins() to find your board defaults


// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF 430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL 100.0

void printSpiPins()
{
  Serial.println();
  Serial.println("======================");
  Serial.println("Hardware SPI GPIO pins");
  Serial.print("MOSI: \t");
  Serial.println(MOSI);
  Serial.print("MISO: \t");
  Serial.println(MISO);
  Serial.print("SCK: \t");
  Serial.println(SCK);
  Serial.print("SS: \t");
  Serial.println(SS);
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  printSpiPins();
  maxe.begin(MAX31865_3WIRE); // set to 2WIRE or 4WIRE as necessary
}

void loop()
{
  // uint16_t rtd = maxe.readRTD();

  // Serial.print("RTD value: "); Serial.println(rtd);
  // Serial.println(rtd);
  // float ratio = rtd;
  // ratio /= 32768;
  // Serial.print("Ratio = "); Serial.println(ratio,8);
  // Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Temperature = ");
  Serial.println(maxe.temperature(RNOMINAL, RREF));

  // Check and print any faults
  uint8_t fault = maxe.readFault();
  if (fault)
  {
    Serial.print("Fault 0x");
    Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH)
    {
      Serial.println("RTD High Threshold");
    }
    if (fault & MAX31865_FAULT_LOWTHRESH)
    {
      Serial.println("RTD Low Threshold");
    }
    if (fault & MAX31865_FAULT_REFINLOW)
    {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (fault & MAX31865_FAULT_REFINHIGH)
    {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_RTDINLOW)
    {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_OVUV)
    {
      Serial.println("Under/Over voltage");
    }
    maxe.clearFault();
  }

  delay(1000);
}