#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern float r_real;
extern float r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const float x_real0 = (((const float *)X)[2 * (ix)]);
    const float x_imag0 = (((const float *)X)[2 * (ix) + 1]);
    const float y_real0 = (((const float *)Y)[2 * (iy)]);
    const float y_imag0 = (((const float *)Y)[2 * (iy) + 1]);
    r_real += x_real0 * y_real0 - 1. * x_imag0 * y_imag0;
    r_imag += x_real0 * y_imag0 + 1. * x_imag0 * y_real0;
    ix += incX;
    iy += incY;

    if (i + 1 < N) {
        const float x_real1 = (((const float *)X)[2 * (ix)]);
        const float x_imag1 = (((const float *)X)[2 * (ix) + 1]);
        const float y_real1 = (((const float *)Y)[2 * (iy)]);
        const float y_imag1 = (((const float *)Y)[2 * (iy) + 1]);
        r_real += x_real1 * y_real1 - 1. * x_imag1 * y_imag1;
        r_imag += x_real1 * y_imag1 + 1. * x_imag1 * y_real1;
        ix += incX;
        iy += incY;
    }
}
}
