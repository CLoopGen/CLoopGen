#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const float y_real = (((float *)Y)[2 * (iy)]);
        const float y_imag = (((float *)Y)[2 * (iy) + 1]);
        float tmpR, tmpI;

        if (beta_imag == 0.0f) {
            tmpR = y_real * beta_real;
            tmpI = y_imag * beta_real;
        } else {
            tmpR = y_real * beta_real - y_imag * beta_imag;
            tmpI = y_real * beta_imag + y_imag * beta_real;
        }

        (((float *)Y)[2 * (iy)]) = tmpR;
        (((float *)Y)[2 * (iy) + 1]) = tmpI;
        iy += incY;
    }
}
