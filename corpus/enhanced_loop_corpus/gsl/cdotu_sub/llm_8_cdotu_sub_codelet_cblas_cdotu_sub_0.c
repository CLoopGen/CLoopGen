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
    if (i + 1 < N) {
        const float x_real1 = (((const float *)X)[2 * (ix)]);
        const float x_imag1 = (((const float *)X)[2 * (ix) + 1]);
        const float y_real1 = (((const float *)Y)[2 * (iy)]);
        const float y_imag1 = (((const float *)Y)[2 * (iy) + 1]);
        r_real += x_real1 * y_real1 - x_imag1 * y_imag1;
        r_imag += x_real1 * y_imag1 + x_imag1 * y_real1;

        const float x_real2 = (((const float *)X)[2 * (ix + incX)]);
        const float x_imag2 = (((const float *)X)[2 * (ix + incX) + 1]);
        const float y_real2 = (((const float *)Y)[2 * (iy + incY)]);
        const float y_imag2 = (((const float *)Y)[2 * (iy + incY) + 1]);
        r_real += x_real2 * y_real2 - x_imag2 * y_imag2;
        r_imag += x_real2 * y_imag2 + x_imag2 * y_real2;

        ix += 2 * incX;
        iy += 2 * incY;
    } else {
        const float x_real = (((const float *)X)[2 * (ix)]);
        const float x_imag = (((const float *)X)[2 * (ix) + 1]);
        const float y_real = (((const float *)Y)[2 * (iy)]);
        const float y_imag = (((const float *)Y)[2 * (iy) + 1]);
        r_real += x_real * y_real - x_imag * y_imag;
        r_imag += x_real * y_imag + x_imag * y_real;
        ix += incX;
        iy += incY;
    }
}
}
