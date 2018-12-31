#include <stdio.h>
#include <stdint.h>
#include "libTLC5947.h"
void return_array(const uint16_t *arrayIn, uint8_t *arrayOut, uint16_t size) {
  int i;
  for (i = 0; i < size; i++) {
    arrayOut[i] = (uint8_t)(arrayIn[i] << 4);
  }
}

void f(uint8_t *a) {
  uint8_t *p;
  p = a;
  printf("a = %p, p = %p, *p = %i\n",a, p, *p);
}

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
  for (i = 0; i < 36; i++) {
    printf("%X, ", dataOut[i]);
  }
  printf("\n");

  uint8_t data1 = 0;
  uint8_t data2[2] = {1, 2};
  f(&data1);
  f(data2);

  return 0;
}
