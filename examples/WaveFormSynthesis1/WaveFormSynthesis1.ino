/*
* File: WaveformSynthesis1.ino
* Purpose: Walsh sinewave synthesis example for Arduino
* Version: 1.0.2
* Release date: 28-01-2021
* Last edit: 01-10-2022
*
* Version history:
* v1.0.1 : signed weigth factors
* v1.0.2 : renaming weight factors
*
* URL: https://github.com/MartinStokroos/WalshFUN
* 
* License: MIT License
* 
*/

#include "walshFun.h"

#define LOOP_PERIOD 62500 // loop time in us. (sampling with 1/16s for a 1 Hz period)

int k, t = 0;
float output = 0.0;
unsigned long nextLoop;

const float w1=0.6407, w5=-0.2654, w9=-0.0528, w13=-0.1275; // weighting factors for sinusoidal output wave.

walshFun func;


void setup() {
  Serial.begin(115200);

  nextLoop = micros() + LOOP_PERIOD; //Set the loop timer interval.
}


void loop() {
  Serial.println(output); // print previous output
  
  output = 0;
  func.wal16(1, t) ? output += w1 : output -= w1;
  func.wal16(5, t) ? output += w5 : output -= w5;
  func.wal16(9, t) ? output += w9 : output -= w9;
  func.wal16(13, t) ? output += w13 : output -= w13;
  
  t++;
  if(t == 16) {t = 0;}

  while(nextLoop > micros()) {
    nextLoop += LOOP_PERIOD;
  }
}

/*
 * The output wave could also have been normalized to 128 by changing the weight factors to send the output to analog out with analogWrite().
 * 
 * The wave components (wal 1, 5, 9 and 13) can also be directed (each individually) to the digital output ports with digitalWrite().
 * Then, each of the individual digital outputs must be added up with an external analog OPAMP summing amplifier. The weight factors 
 * of the wave components must be 'programmed' in resistor values.
 * 
 */
