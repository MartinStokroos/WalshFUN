/*
* File: WaveformSynthesis1.ino
* Purpose: Walsh sinewave synthesis example for Arduino
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

int k, t = 0;
float output = 0.0;
unsigned long nextLoop;

const float w1=0.6407, w2=0.2654, w3=0.0528, w4=0.1275; // weight factors for sinusoidal output wave.

walshFun func;


void setup() {
  Serial.begin(115200);

  nextLoop = micros() + LPERIOD; //Set the loop timer interval.
}


void loop() {

  Serial.println(output); // print previous output
  
  output = 0;
  func.wal16(1, t) ? output += w1 : output -= w1;
  func.wal16(5, t) ? output -= w2 : output += w2;
  func.wal16(9, t) ? output -= w3 : output += w3;
  func.wal16(13, t) ? output -= w4 : output += w4;
  
  t++;
  if(t == 16) {t = 0;}

  while(nextLoop > micros()) {
    nextLoop += LPERIOD;
  }
  
}

/*
 * The output wave could be normalized to 128 by changing the weight factors for sending the output to analog out with analogWrite().
 * 
 * The wave components (wal 1, 5, 9 and 13) can also be directed (each individually) to the digital output ports with digitalWrite().
 * Then, each of the individual digital outputs must be added up with an external analog OPAMP summing amplifier. The weight factors 
 * of the wave components must be 'programmed' in the resistor values.
 * 
 */
