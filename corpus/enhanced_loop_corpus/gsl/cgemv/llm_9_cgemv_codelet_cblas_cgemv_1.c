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
const int unroll_factor = 4;
int limit = (lenY / unroll_factor) * unroll_factor;
for (i = 0; i < limit; i += unroll_factor) {
    for (int j = 0; j < unroll_factor; j++) {
        const float y_real = (((float *)Y)[2 * (iy)]);
        const float y_imag = (((float *)Y)[2 * (iy) + 1]);
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        (((float *)Y)[2 * (iy)]) = tmpR;
        (((float *)Y)[2 * (iy) + 1]) = tmpI;
        iy += incY;
    }
}
for (; i < lenY; i++) {
    const float y_real = (((float *)Y)[2 * (iy)]);
    const float y_imag = (((float *)Y)[2 * (iy) + 1]);
    const float tmpR = y_real * beta_real - y_imag * beta_imag;
    const float tmpI = y_real * beta_imag + y_imag * beta_real;
    (((float *)Y)[2 * (iy)]) = tmpR;
    (((float *)Y)[2 * (iy) + 1]) = tmpI;
    iy += incY;
}
}
