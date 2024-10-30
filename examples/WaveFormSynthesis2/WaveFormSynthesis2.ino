/*
* File: WaveformSynthesis2.ino
* Purpose: Walsh sawtooth wave synthesis example for Arduino
* Version: 1.0.2
* Release date: 28-01-2021
* Last edit: 01-10-2022
*
* Version history:
* v1.0.1 : signed weighting factors
* v1.0.2 : renaming weighting factors
*
* URL: https://github.com/MartinStokroos/WalshFUN
* 
* License: MIT License
* 
*/

#include "walshFun.h"

#define LOOP_PERIOD 62500 // loop time in us. (sampling with 1/16s for a 1 Hz period)

int analogPin = 3;
int k, t = 0;
int output = 0;
unsigned long nextLoop;

const unsigned int w1=-64, w3=-32, w7=-16, w15=-8; // weighting factors for a sawtooth wave.

walshFun func;


void setup() {
  Serial.begin(115200);

  nextLoop = micros() + LOOP_PERIOD; //Set the loop timer interval.
}


void loop() {
  analogWrite(analogPin, output + 128);
  Serial.println(output); // print previous output.
  
  output = 0;
  func.wal16(1, t) ? output += w1 : output -= w1;
  func.wal16(3, t) ? output += w3 : output -= w3;
  func.wal16(7, t) ? output += w7 : output -= w7;
  func.wal16(15, t) ? output += w15 : output -= w15;
  
  t++;
  if(t == 16) {t = 0;}

  while(nextLoop > micros()) {
    nextLoop += LOOP_PERIOD;
  }
}

/*
 * The wave components (wal 1, 3, 7 and 15) can also be directed (each individually) to the digital output ports with digitalWrite().
 * Then, each of the individual digital outputs must be added up with an external analog OPAMP summing amplifier. The weight factors 
 * of the wave components must be 'programmed' in resistor values.
 * 
 */
