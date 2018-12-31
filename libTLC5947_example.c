/******************************************************************************
libTLC5947_example.c
Example code using the Library for the TI TLC5947 24 Channel 12-Bit PWM LED
Driver.
*******************************************************************************
The MIT License (MIT)

Copyright (c) 2016 Matthew Klein

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include <stdio.h>
#include "libTLC5947.h"

int main(void) {
  uint16_t dataIn[24] = {0x0000, 0x0001, 0x0002, 0x0003,
			 0x0004, 0x0005, 0x0006, 0x0007,
			 0x0008, 0x0009, 0x000A, 0x000B,
			 0x000C, 0x000D, 0x000E, 0x000F,
			 0x0010, 0x0012, 0x0013, 0x0014,
			 0x0015, 0x0016, 0x0017, 0x0018};
  uint8_t dataOut[36];
  Nbit_array_to_8bit_array(dataIn, 24, 12, dataOut, 36);
  int i;
  for (i = 0; i < 24; i++) {
    printf("%.3X", dataIn[23-i]);
  }
  printf("\n");

  printf("");
  for (i = 0; i < 36; i++) {
    printf("%.2X", dataOut[i]);
  }
  printf("\n");
  return 0;
}
