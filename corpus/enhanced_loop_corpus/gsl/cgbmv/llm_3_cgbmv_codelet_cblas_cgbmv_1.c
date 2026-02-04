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
    // Variant 2: Strided array access using a step size derived from incY
    float *y_base = (float *)Y;
    int stride = 2 * incY; // Full complex stride in float units
    int index = 0;
    for (i = 0; i < lenY; i++) {
        const float y_real = y_base[index];
        const float y_imag = y_base[index + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        y_base[index] = tmpR;
        y_base[index + 1] = tmpI;
        index += stride;
    }
}
