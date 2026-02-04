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
for (i = 0; i < lenY; i += 2) {
    if (i + 1 < lenY) {
        const float y1_real = (((float *)Y)[2 * (iy)]);
        const float y1_imag = (((float *)Y)[2 * (iy) + 1]);
        const float y2_real = (((float *)Y)[2 * (iy + incY)]);
        const float y2_imag = (((float *)Y)[2 * (iy + incY) + 1]);

        const float tmp1R = y1_real * beta_real - y1_imag * beta_imag;
        const float tmp1I = y1_real * beta_imag + y1_imag * beta_real;
        const float tmp2R = y2_real * beta_real - y2_imag * beta_imag;
        const float tmp2I = y2_real * beta_imag + y2_imag * beta_real;

        (((float *)Y)[2 * (iy)]) = tmp1R;
        (((float *)Y)[2 * (iy) + 1]) = tmp1I;
        (((float *)Y)[2 * (iy + incY)]) = tmp2R;
        (((float *)Y)[2 * (iy + incY) + 1]) = tmp2I;
    } else {
        const float y_real = (((float *)Y)[2 * (iy)]);
        const float y_imag = (((float *)Y)[2 * (iy) + 1]);
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        (((float *)Y)[2 * (iy)]) = tmpR;
        (((float *)Y)[2 * (iy) + 1]) = tmpI;
    }
    iy += 2 * incY;
}
}
