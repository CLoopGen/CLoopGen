#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int stride = 2 * incY;
int base_offset = 2 * iy;
for (i = 0; i < lenY; i++) {
    const double y_real = ((double*)Y)[base_offset];
    const double y_imag = ((double*)Y)[base_offset + 1];
    const double tmpR = y_real * beta_real - y_imag * beta_imag;
    const double tmpI = y_real * beta_imag + y_imag * beta_real;
    ((double*)Y)[base_offset] = tmpR;
    ((double*)Y)[base_offset + 1] = tmpI;
    base_offset += stride;
}
}
