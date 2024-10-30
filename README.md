# WalshFUN 

## Walsh functions library for Arduino
Walsh functions [1] are a set of orthogonal functions that serve as discrete analogs to traditional sine and cosine functions used in Fourier analysis. They are defined on a finite interval and can be particularly useful in various applications, including signal processing, data compression, and error correction.

Unlike sine and cosine functions, which produce a continuous range of values, Walsh functions take on only two discrete states: +1 and -1. This binary output makes them suitable for digital applications and allows them to represent signals in a simple, yet effective manner.

The Walsh functions are organized in a hierarchical structure, often represented in a matrix format known as the Walsh matrix. Each row of this matrix corresponds to a different Walsh function, allowing for straightforward computation and transformation of signals. The orthogonality property of these functions ensures that they can be used to decompose a signal into its constituent parts without interference from other components.

In the context of Arduino applications, the implementation of Walsh functions can yield output in the form of boolean values—specifically, logic states of 1 or 0. This allows for straightforward integration into digital circuits and algorithms, where binary logic is essential. By leveraging Walsh functions, developers can create efficient solutions for tasks such as waveform generation, modulation, and pattern recognition, harnessing the power of orthogonal functions in a discrete, binary framework.

--- 

This library and examples provides a simple introduction to start experimenting with Walsh functions, especially in the context of digital systems like Arduino.

The Walsh function is noted down as:

*WAL(n, t)* ,where:

*n* is the 'frequency' or wave number,

*t* is the time, usually normalized to the time base *t/T*.

The even Walsh functions are sometimes labeled as *CAL* and the odd Walsh functions as *SAL*.

## Walsh functions in the library
* `bool wal8(unsigned char n, unsigned char t)`
* `bool wal16(unsigned char n, unsigned char t)`
* `bool wal32(unsigned char n, unsigned char t)`
* `bool wal64(unsigned char n, unsigned char t)`
* `bool wal128(unsigned char n, unsigned char t)`
* `bool wal256(unsigned char n, unsigned char t)`

## Examples
1. `WalshFunctionSeries.ino` - This example prints the first 32 Walsh functions in 32 timesteps. The logic '1' is printed as '*+*' and the  logic '0' as '*-*'. See below.
2. `WaveFormSynthesis1` - This example generates a sinewave from Walsh functions.
3. `WaveFormSynthesis2` - This example generates a sawtooth wave from Walsh functions.

Use the Arduino plotter function with example 2 and 3.


```
++++++++++++++++++++++++++++++++ WAL(0,T)
++++++++++++++++---------------- WAL(1,T)
++++++++----------------++++++++ WAL(2,T)
++++++++--------++++++++-------- WAL(3,T)
++++--------++++++++--------++++ WAL(4,T)
++++--------++++----++++++++---- WAL(5,T)
++++----++++--------++++----++++ WAL(6,T)
++++----++++----++++----++++---- WAL(7,T)
++----++++----++++----++++----++ WAL(8,T)
++----++++----++--++++----++++-- WAL(9,T)
++----++--++++----++++--++----++ WAL(10,T)
++----++--++++--++----++--++++-- WAL(11,T)
++--++----++--++++--++----++--++ WAL(12,T)
++--++----++--++--++--++++--++-- WAL(13,T)
++--++--++--++----++--++--++--++ WAL(14,T)
++--++--++--++--++--++--++--++-- WAL(15,T)
+--++--++--++--++--++--++--++--+ WAL(16,T)
+--++--++--++--+-++--++--++--++- WAL(17,T)
+--++--+-++--++--++--++-+--++--+ WAL(18,T)
+--++--+-++--++-+--++--+-++--++- WAL(19,T)
+--+-++--++-+--++--+-++--++-+--+ WAL(20,T)
+--+-++--++-+--+-++-+--++--+-++- WAL(21,T)
+--+-++-+--+-++--++-+--+-++-+--+ WAL(22,T)
+--+-++-+--+-++-+--+-++-+--+-++- WAL(23,T)
+-+--+-++-+--+-++-+--+-++-+--+-+ WAL(24,T)
+-+--+-++-+--+-+-+-++-+--+-++-+- WAL(25,T)
+-+--+-+-+-++-+--+-++-+-+-+--+-+ WAL(26,T)
+-+--+-+-+-++-+-+-+--+-+-+-++-+- WAL(27,T)
+-+-+-+--+-+-+-++-+-+-+--+-+-+-+ WAL(28,T)
+-+-+-+--+-+-+-+-+-+-+-++-+-+-+- WAL(29,T)
+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+ WAL(30,T)
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- WAL(31,T)

++++++++++++++++---------------- SAL(1,T)
++++++++--------++++++++-------- SAL(2,T)
++++--------++++----++++++++---- SAL(3,T)
++++----++++----++++----++++---- SAL(4,T)
++----++++----++--++++----++++-- SAL(5,T)
++----++--++++--++----++--++++-- SAL(6,T)
++--++----++--++--++--++++--++-- SAL(7,T)
++--++--++--++--++--++--++--++-- SAL(8,T)
+--++--++--++--+-++--++--++--++- SAL(9,T)
+--++--+-++--++-+--++--+-++--++- SAL(10,T)
+--+-++--++-+--+-++-+--++--+-++- SAL(11,T)
+--+-++-+--+-++-+--+-++-+--+-++- SAL(12,T)
+-+--+-++-+--+-+-+-++-+--+-++-+- SAL(13,T)
+-+--+-+-+-++-+-+-+--+-+-+-++-+- SAL(14,T)
+-+-+-+--+-+-+-+-+-+-+-++-+-+-+- SAL(15,T)
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- SAL(16,T)

++++++++----------------++++++++ CAL(1,T)
++++--------++++++++--------++++ CAL(2,T)
++++----++++--------++++----++++ CAL(3,T)
++----++++----++++----++++----++ CAL(4,T)
++----++--++++----++++--++----++ CAL(5,T)
++--++----++--++++--++----++--++ CAL(6,T)
++--++--++--++----++--++--++--++ CAL(7,T)
+--++--++--++--++--++--++--++--+ CAL(8,T)
+--++--+-++--++--++--++-+--++--+ CAL(9,T)
+--+-++--++-+--++--+-++--++-+--+ CAL(10,T)
+--+-++-+--+-++--++-+--+-++-+--+ CAL(11,T)
+-+--+-++-+--+-++-+--+-++-+--+-+ CAL(12,T)
+-+--+-+-+-++-+--+-++-+-+-+--+-+ CAL(13,T)
+-+-+-+--+-+-+-++-+-+-+--+-+-+-+ CAL(14,T)
+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+ CAL(15,T)

```

[1]: https://en.wikipedia.org/wiki/Walsh_function
