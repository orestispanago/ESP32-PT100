#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MAX31865.h>

// Use software SPI: CS, DI, DO, CLK
// Adafruit_MAX31865 maxe = Adafruit_MAX31865(15, 18, 4, 5); // As marked on board

// use hardware SPI, just pass in the CS pin
// Use print_spi_pins() to find your board defaults
Adafruit_MAX31865 temp1 = Adafruit_MAX31865(15); // As marked on board
// Adafruit_MAX31865 temp2 = Adafruit_MAX31865(4);

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
  // printSpiPins();
  temp1.begin(MAX31865_3WIRE); // set to 2WIRE or 4WIRE as necessary
  // temp2.begin(MAX31865_3WIRE); // set to 2WIRE or 4WIRE as necessary
}

void loop()
{

  Serial.print("temp1 = ");
  Serial.println(temp1.temperature(RNOMINAL, RREF));
  // Serial.print("temp2 = ");
  // Serial.println(temp2.temperature(RNOMINAL, RREF));
  delay(1000);
}