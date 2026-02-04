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
    float prev_tmpR = 0.0f, prev_tmpI = 0.0f;
    for (i = 0; i < lenY; i++) {
        const float y_real = (((float *)Y)[2 * (iy)]);
        const float y_imag = (((float *)Y)[2 * (iy) + 1]);
        const float tmpR = y_real * beta_real - y_imag * beta_imag + prev_tmpR;
        const float tmpI = y_real * beta_imag + y_imag * beta_real + prev_tmpI;
        (((float *)Y)[2 * (iy)]) = tmpR;
        (((float *)Y)[2 * (iy) + 1]) = tmpI;
        prev_tmpR = tmpR;
        prev_tmpI = tmpI;
        iy += incY;
    }
}
