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
    float local_accum_real = beta_real;
    float local_accum_imag = beta_imag;
    for (i = 0; i < lenY; i++) {
        const float y_real = (((float *)Y)[2 * (iy)]);
        const float y_imag = (((float *)Y)[2 * (iy) + 1]);
        local_accum_real *= 0.99f;
        local_accum_imag *= 0.99f;
        const float tmpR = y_real * local_accum_real - y_imag * local_accum_imag;
        const float tmpI = y_real * local_accum_imag + y_imag * local_accum_real;
        (((float *)Y)[2 * (iy)]) = tmpR;
        (((float *)Y)[2 * (iy) + 1]) = tmpI;
        iy += incY;
    }
}
