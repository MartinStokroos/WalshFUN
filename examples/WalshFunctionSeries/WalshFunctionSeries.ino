/*
* File: WalshFunctionSeries.ino
* Purpose: Walsh function example for Arduino
* Version: 1.0.0
* Release date: 28-01-2021
* Last edit:
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

#define N 32

int k, t, n;

walshFun func; // create instance of walshFun


void setup() {
  Serial.begin(115200);
}


void loop() {
  
  for (k = 0; k < N; k++) {
    for (t = 0; t < N; t++) {

      if (func.wal32(k, t)) {
        Serial.print("+");
      }
      else {
        Serial.print("-");
      }
    }
    Serial.print(" WAL(");
    Serial.print(k);
    Serial.println(",T)");
  }

  Serial.println();

  n=1;
  for (k = 1; k < N; k++)
  {
    if (k & 1) //odd WAL = SAL
    {
      for (t = 0; t < N; t++)
      {
        if (func.wal32(k, t))
        {
          Serial.print("+");
        }
        else
        {
          Serial.print("-");
        }
      }
      Serial.print(" SAL(");
      Serial.print(n);
      Serial.println(",T)");
      n++;
    }
  }

  Serial.println();  

  n=1;
  for (k = 1; k < N; k++)
  {
    if (!(k & 1)) //even WAL = CAL
    {
      for (t = 0; t < N; t++)
      {
        if (func.wal32(k, t))
        {
          Serial.print("+");
        }
        else
        {
          Serial.print("-");
        }
      }
      Serial.print(" CAL(");
      Serial.print(n);
      Serial.println(",T)");
      n++;
    }
  }

  while (1) {};
}
