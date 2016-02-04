/******************************************************************************
libTLC5947.c
Library for the TI TLC5947 24 Channel 12-Bit PWM LED Driver.
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

unsigned char * convert_24x12bit_to_36x8bit(unsigned short dataIn[24]) {
  // dataIn contains 24 12 bit numbers wrapped in 16 bit containers. So
  // dataIn[i] & 0x0FFF = dataIn[i] for all i.
  // Each 12 bit number of dataIn will be fed sequentially into an array of 8
  // bit numbers starting sequentially with the MSB of dataIn[23] and ending
  // with the LSB of dataIn[0].

  // Create the 8 bit array, dataOut.
  static unsigned char dataOut[36];

  // Then iterate, backwards, through each element of dataIn
  // For each 12 bit number of dataIn, 1.5 8 bit numbers of dataOut will be
  // filled.
  // Used fixed n = 24
  int n = 24;
  for ( int i = 0; i < n; i++ ) {
    if ((i+1)%2) {// If i is even ...
      // MS 8 bits of dataIn fills whole byte of dataOut
      dataOut[(int)(i*1.5)] = ( dataIn[(n-1)-i] >> 4 ) & 0x00FF;
      // LS 4 bits of dataIn fills upper half of byte of dataOut
      dataOutut[(int)(i*1.5+1)] = ( dataIn[(n-1)-i] << 4 ) & 0x00F0;
    }
    else {// If i is odd ...
      // MS 4 bits of dataIn fills lower half of byte of dataOut
      dataOut[(int)(i*1.5-0.5)] |= ( dataIn[(n-1)-i] >> 8 ) & 0x000F;
      // LS 8 bits of dataIn fills whole byte of dataOut
      dataOut[(int)(i*1.5-0.5+1)] = ( dataIn[(n-1)-i] ) & 0x00FF;
    }
  }

  return dataOut;
}
