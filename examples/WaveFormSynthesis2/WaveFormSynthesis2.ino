/*
* File: WaveformSynthesis2.ino
* Purpose: Walsh saw-tooth wave synthesis example for Arduino
* Version: 1.0.0
* Release date: 28-01-2021
*
* Version history:
*
*
* URL: https://github.com/MartinStokroos/WalshFUN
* 
* License: MIT License
* 
*/

#include "walshFun.h"

#define LPERIOD 62500 // loop time in us. (sampling with 1/16s for a 1 Hz period)

int analogPin = 3;
int k, t = 0;
float output = 0.0;
unsigned long nextLoop;

const unsigned int w1=64, w2=32, w3=16, w4=8; // weight factors for sinusoidal output wave.

walshFun func;


void setup() {
  Serial.begin(115200);

  nextLoop = micros() + LPERIOD; //Set the loop timer interval.
}


void loop() {

  analogWrite(analogPin, output + 128);
  Serial.println(output); // print previous output.
  
  output = 0;
  func.wal16(1, t) ? output -= w1 : output += w1;
  func.wal16(3, t) ? output -= w2 : output += w2;
  func.wal16(7, t) ? output -= w3 : output += w3;
  func.wal16(15, t) ? output -= w4 : output += w4;
  
  t++;
  if(t == 16) {t = 0;}

  while(nextLoop > micros()) {
    nextLoop += LPERIOD;
  }
  
}

/*
 * The wave components (wal 1, 3, 7 and 9) can also be directed individually to digital output ports with digitalWrite().
 * Then the individual digital outputs must be added up with an external analog OPAMP summing amplifier. The weight factors 
 * of the wave components must be 'programmed' in the resistor values.
 * 
 */
