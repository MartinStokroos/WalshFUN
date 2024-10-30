/*
* File: walshFun.h
* Purpose: Walsh functions for Arduino
* Version: 1.0.3
* Release date: 28-01-2021
* Last edit: 30-10-2024
*
* Version history:
* rev. 1.0.1 - fixed some lookup tables.
* rev. 1.0.2 - tables data type changed to unsigned char to prevent 'narrowing conversion' problems.
* rev. 1.0.3 - one lookup table for all Walsh functions of different size.
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


// Gray-code table (LSB first).

const unsigned char gray_lut256[] PROGMEM = {
  B00000000,
  B10000000,
  B11000000,
  B01000000,
  B01100000,
  B11100000,
  B10100000,
  B00100000,
  B00110000,
  B10110000,
  B11110000,
  B01110000,
  B01010000,
  B11010000,
  B10010000,
  B00010000,
  B00011000,
  B10011000,
  B11011000,
  B01011000,
  B01111000,
  B11111000,
  B10111000,
  B00111000,
  B00101000,
  B10101000,
  B11101000,
  B01101000,
  B01001000,
  B11001000,
  B10001000,
  B00001000,
  B00001100,
  B10001100,
  B11001100,
  B01001100,
  B01101100,
  B11101100,
  B10101100,
  B00101100,
  B00111100,
  B10111100,
  B11111100,
  B01111100,
  B01011100,
  B11011100,
  B10011100,
  B00011100,
  B00010100,
  B10010100,
  B11010100,
  B01010100,
  B01110100,
  B11110100,
  B10110100,
  B00110100,
  B00100100,
  B10100100,
  B11100100,
  B01100100,
  B01000100,
  B11000100,
  B10000100,
  B00000100,
  B00000110,
  B10000110,
  B11000110,
  B01000110,
  B01100110,
  B11100110,
  B10100110,
  B00100110,
  B00110110,
  B10110110,
  B11110110,
  B01110110,
  B01010110,
  B11010110,
  B10010110,
  B00010110,
  B00011110,
  B10011110,
  B11011110,
  B01011110,
  B01111110,
  B11111110,
  B10111110,
  B00111110,
  B00101110,
  B10101110,
  B11101110,
  B01101110,
  B01001110,
  B11001110,
  B10001110,
  B00001110,
  B00001010,
  B10001010,
  B11001010,
  B01001010,
  B01101010,
  B11101010,
  B10101010,
  B00101010,
  B00111010,
  B10111010,
  B11111010,
  B01111010,
  B01011010,
  B11011010,
  B10011010,
  B00011010,
  B00010010,
  B10010010,
  B11010010,
  B01010010,
  B01110010,
  B11110010,
  B10110010,
  B00110010,
  B00100010,
  B10100010,
  B11100010,
  B01100010,
  B01000010,
  B11000010,
  B10000010,
  B00000010,
  B00000011,
  B10000011,
  B11000011,
  B01000011,
  B01100011,
  B11100011,
  B10100011,
  B00100011,
  B00110011,
  B10110011,
  B11110011,
  B01110011,
  B01010011,
  B11010011,
  B10010011,
  B00010011,
  B00011011,
  B10011011,
  B11011011,
  B01011011,
  B01111011,
  B11111011,
  B10111011,
  B00111011,
  B00101011,
  B10101011,
  B11101011,
  B01101011,
  B01001011,
  B11001011,
  B10001011,
  B00001011,
  B00001111,
  B10001111,
  B11001111,
  B01001111,
  B01101111,
  B11101111,
  B10101111,
  B00101111,
  B00111111,
  B10111111,
  B11111111,
  B01111111,
  B01011111,
  B11011111,
  B10011111,
  B00011111,
  B00010111,
  B10010111,
  B11010111,
  B01010111,
  B01110111,
  B11110111,
  B10110111,
  B00110111,
  B00100111,
  B10100111,
  B11100111,
  B01100111,
  B01000111,
  B11000111,
  B10000111,
  B00000111,
  B00000101,
  B10000101,
  B11000101,
  B01000101,
  B01100101,
  B11100101,
  B10100101,
  B00100101,
  B00110101,
  B10110101,
  B11110101,
  B01110101,
  B01010101,
  B11010101,
  B10010101,
  B00010101,
  B00011101,
  B10011101,
  B11011101,
  B01011101,
  B01111101,
  B11111101,
  B10111101,
  B00111101,
  B00101101,
  B10101101,
  B11101101,
  B00001001,
  B10001001,
  B11001001,
  B01001001,
  B01101001,
  B11101001,
  B10101001,
  B00101001,
  B00111001,
  B10111001,
  B11111001,
  B01111001,
  B01011001,
  B11011001,
  B10011001,
  B00011001,
  B00010001,
  B10010001,
  B11010001,
  B01010001,
  B01110001,
  B11110001,
  B10110001,
  B00110001,
  B00100001,
  B10100001,
  B11100001,
  B01100001,
  B01000001,
  B11000001,
  B10000001,
  B00000001
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
  // nothing
};

#endif /* walshFun_H_ */



