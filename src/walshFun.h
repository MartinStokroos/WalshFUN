/*
* File: walshFun.h
* Purpose: Walsh functions for Arduino
* Version: 1.0.0
* Release date: 28-01-2021
* Last edit:
*
* Version history:
*
*
* URL: https://github.com/MartinStokroos/WalshFUN
* License: MIT License
*
*
* Copyright (c) M.Stokroos 2021
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
* files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
* modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
* Software is furnished to do so, subject to the following conditions:
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*/


#ifndef walshFun_H_
#define walshFun_H_

#include "Arduino.h"
#include "avr/pgmspace.h"


// Gray-code tables (LSB first).
const char gray_lut8[] PROGMEM = {
  B000,
  B100,
  B110,
  B010,
  B011,
  B111,
  B101,
  B001
};

const char gray_lut16[] PROGMEM = {
  B0000,
  B1000,
  B1100,
  B0100,
  B0110,
  B1110,
  B1010,
  B0010,
  B0011,
  B1011,
  B1111,
  B0111,
  B0101,
  B1101,
  B1001,
  B0001
};

const char gray_lut32[] PROGMEM = {
  B00000,
  B10000,
  B11000,
  B01000,
  B01100,
  B11100,
  B10100,
  B00100,
  B00110,
  B10110,
  B11110,
  B01110,
  B01010,
  B11010,
  B10010,
  B00010,
  B00011,
  B10011,
  B11011,
  B01011,
  B01111,
  B11111,
  B10111,
  B00111,
  B00101,
  B10101,
  B11101,
  B01101,
  B01001,
  B11001,
  B10001,
  B00001
};


const char gray_lut64[] PROGMEM = {// table under construction
};


const char gray_lut128[] PROGMEM = {// table under construction
};


const char gray_lut256[] PROGMEM = {// table under construction
};


// Compute parity by lookup table, taken from:
// http://graphics.stanford.edu/~seander/bithacks.html#ParityLookupTable
const bool parityTable256[256] = {
  #define P2(n) n, n^1, n^1, n
  #define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
  #define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
  P6(0), P6(1), P6(1), P6(0)
};




class walshFun {
public:
  bool wal8(unsigned char _n, unsigned char _t);
  bool wal16(unsigned char _n, unsigned char _t);
  bool wal32(unsigned char _n, unsigned char _t);
  bool wal64(unsigned char _n, unsigned char _t);
  bool wal128(unsigned char _n, unsigned char _t);
  bool wal256(unsigned char _n, unsigned char _t);
private:

};


#endif /* walshFun_H_ */



