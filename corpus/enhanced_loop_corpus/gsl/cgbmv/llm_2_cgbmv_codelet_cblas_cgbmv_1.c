#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *y_ptr = (float *)Y;
    for (i = 0; i < lenY; i++) {
        const float y_real = y_ptr[2 * iy];
        const float y_imag = y_ptr[2 * iy + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        y_ptr[2 * iy] = tmpR;
        y_ptr[2 * iy + 1] = tmpI;
        iy += incY;
    }
}
