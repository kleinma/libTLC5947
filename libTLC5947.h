/******************************************************************************
libTLC5947.h
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

#include <stdint.h>

#ifndef __LIBTLC5947_H_INCLUDED__
#define __LIBTLC5947_H_INCLUDED__

/*! ---------------------------------------------------------------------------
 * @fn Nbit_array_to_8bit_array()
 *
 * @brief This function unpacks the N LSBs of integers in a 16 bit array and
 * packages them sequentially in an 8 bit array starting with the MSB of the
 * last element of the array. This can be used to transform data whose length
 * is not divisible by 8 bits and send it MSB first over a hardware SPI.
 *
 * input parameters:
 * @param dataIn      - Pointer to an array of 16 bit integers containing 0-16
 *                      bit data.
 * @param dataInSize  - Number of elements in dataIn.
 * @param dataInBits  - Number between 0 and 16. This is the MSB of dataIn that
 *                      will be placed in dataOut.
 * @param dataOut     - Pointer to an array of 8 bit integers that will contain
 *                      all the data that was in dataIn.
 * @param dataOutSize - number of elements in dataOut. Should be
 *                      dataOutSize = dataInSize*dataInBits/8
 *
 * output parameters:
 *
 * @returns           - 0 for succes, or 1 for error
 */
int Nbit_array_to_8bit_array(const uint16_t *dataIn, uint16_t dataInSize,
			     uint16_t dataInBits, uint8_t *dataOut,
			     uint16_t dataOutSize);

#endif
