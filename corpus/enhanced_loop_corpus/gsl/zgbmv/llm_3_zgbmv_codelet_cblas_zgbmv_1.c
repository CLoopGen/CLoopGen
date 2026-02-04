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
const int stride = incY * 2;
int base_index = 2 * iy;
for (i = 0; i < lenY; i++) {
    const int offset = i * stride;
    const double y_real = ((double *)Y)[base_index + offset];
    const double y_imag = ((double *)Y)[base_index + offset + 1];
    const double tmpR = y_real * beta_real - y_imag * beta_imag;
    const double tmpI = y_real * beta_imag + y_imag * beta_real;
    ((double *)Y)[base_index + offset] = tmpR;
    ((double *)Y)[base_index + offset + 1] = tmpI;
}
iy = iy + incY * lenY;
}
