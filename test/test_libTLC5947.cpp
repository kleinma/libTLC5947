/******************************************************************************
test_libTLC5947.cpp
A set of unit tests for libTLC5947.c
*******************************************************************************
The MIT License (MIT)

  Copyright (c) 2016 Matthew A. Klein

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

#include <gtest/gtest.h>
#include "libTLC5947/libTLC5947.h"

TEST(convert_data_test, compile_test) {
  unsigned short dataIn[24] = {0x0000, 0x0001, 0x0002, 0x0003,
			       0x0004, 0x0005, 0x0006, 0x0007,
			       0x0008, 0x0009, 0x000A, 0x000B,
			       0x000C, 0x000D, 0x000E, 0x000F,
			       0x0010, 0x0012, 0x0013, 0x0014,
			       0x0015, 0x0016, 0x0017, 0x0018};

  unsigned char dataOutExpected[36] = {1, 128, 23, 1, 96, 21,
				       1, 64, 19, 1, 32, 16,
				       0, 240, 14, 0, 208, 12,
				       0, 176, 10, 0, 144, 8,
				       0, 112, 6, 0, 80, 4,
				       0, 48, 2, 0, 16, 0};

  unsigned char *dataOutActual;
  dataOutActual = convert_24x12bit_to_36x8bit(dataIn);

  // pointers are confusing!
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(dataOutActual,dataOutExpected);
}

GTEST_API_ int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
