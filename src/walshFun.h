/*
* File: walshFun.h
* Purpose: Walsh functions for Arduino
* Version: 1.0.2
* Release date: 28-01-2021
* Last edit: 28-01-2021
*
* Version history:
* rev. 1.0.1 - fixed some lookup tables.
* rev. 1.0.2 - tables data type changed to unsigned char to prevent narrowing conversion problems.
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
const unsigned char gray_lut8[] PROGMEM = {
  B000,
  B100,
  B110,
  B010,
  B011,
  B111,
  B101,
  B001
};

const unsigned char gray_lut16[] PROGMEM = {
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

const unsigned char gray_lut32[] PROGMEM = {
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


const unsigned char gray_lut64[] PROGMEM = {
  B000000,
  B100000,
  B110000,
  B010000,
  B011000,
  B111000,
  B101000,
  B001000,
  B001100,
  B101100,
  B111100,
  B011100,
  B010100,
  B110100,
  B100100,
  B000100,
  B000110,
  B100110,
  B110110,
  B010110,
  B011110,
  B111110,
  B101110,
  B001110,
  B001010,
  B101010,
  B111010,
  B011010,
  B010010,
  B110010,
  B100010,
  B000010,
  B000011,
  B100011,
  B110011,
  B010011,
  B011011,
  B111011,
  B101011,
  B001011,
  B001111,
  B101111,
  B111111,
  B011111,
  B010111,
  B110111,
  B100111,
  B000111,
  B000101,
  B100101,
  B110101,
  B010101,
  B011101,
  B111101,
  B101101,
  B001101,
  B001001,
  B101001,
  B111001,
  B011001,
  B010001,
  B110001,
  B100001,
  B000001
};


const unsigned char gray_lut128[] PROGMEM = {
  B0000000,
  B1000000,
  B1100000,
  B0100000,
  B0110000,
  B1110000,
  B1010000,
  B0010000,
  B0011000,
  B1011000,
  B1111000,
  B0111000,
  B0101000,
  B1101000,
  B1001000,
  B0001000,
  B0001100,
  B1001100,
  B1101100,
  B0101100,
  B0111100,
  B1111100,
  B1011100,
  B0011100,
  B0010100,
  B1010100,
  B1110100,
  B0110100,
  B0100100,
  B1100100,
  B1000100,
  B0000100,
  B0000110,
  B1000110,
  B1100110,
  B0100110,
  B0110110,
  B1110110,
  B1010110,
  B0010110,
  B0011110,
  B1011110,
  B1111110,
  B0111110,
  B0101110,
  B1101110,
  B1001110,
  B0001110,
  B0001010,
  B1001010,
  B1101010,
  B0101010,
  B0111010,
  B1111010,
  B1011010,
  B0011010,
  B0010010,
  B1010010,
  B1110010,
  B0110010,
  B0100010,
  B1100010,
  B1000010,
  B0000010,
  B0000011,
  B1000011,
  B1100011,
  B0100011,
  B0110011,
  B1110011,
  B1010011,
  B0010011,
  B0011011,
  B1011011,
  B1111011,
  B0111011,
  B0101011,
  B1101011,
  B1001011,
  B0001011,
  B0001111,
  B1001111,
  B1101111,
  B0101111,
  B0111111,
  B1111111,
  B1011111,
  B0011111,
  B0010111,
  B1010111,
  B1110111,
  B0110111,
  B0100111,
  B1100111,
  B1000111,
  B0000111,
  B0000101,
  B1000101,
  B1100101,
  B0100101,
  B0110101,
  B1110101,
  B1010101,
  B0010101,
  B0011101,
  B1011101,
  B1111101,
  B0111101,
  B0101101,
  B1101101,
  B1001101,
  B0001101,
  B0001001,
  B1001001,
  B1101001,
  B0101001,
  B0111001,
  B1111001,
  B1011001,
  B0011001,
  B0010001,
  B1010001,
  B1110001,
  B0110001,
  B0100001,
  B1100001,
  B1000001,
  B0000001
};


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
  B01101101,
  B01001101,
  B11001101,
  B10001101,
  B00001101,
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

};


#endif /* walshFun_H_ */



