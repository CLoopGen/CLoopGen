#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const float x_real1 = (((const float *)X)[2 * (ix)]);
    const float x_imag1 = (((const float *)X)[2 * (ix) + 1]);
    const float x_real2 = (i + 1 < N) ? (((const float *)X)[2 * (ix + incX)]) : 0.0f;
    const float x_imag2 = (i + 1 < N) ? (((const float *)X)[2 * (ix + incX) + 1]) : 0.0f;

    (((float *)Y)[2 * (iy)]) += (alpha_real * x_real1 - alpha_imag * x_imag1);
    (((float *)Y)[2 * (iy) + 1]) += (alpha_real * x_imag1 + alpha_imag * x_real1);

    if (i + 1 < N) {
        (((float *)Y)[2 * (iy + incY)]) += (alpha_real * x_real2 - alpha_imag * x_imag2);
        (((float *)Y)[2 * (iy + incY) + 1]) += (alpha_real * x_imag2 + alpha_imag * x_real2);
    }

    ix += 2 * incX;
    iy += 2 * incY;
}
}
