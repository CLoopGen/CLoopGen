#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const float x_real1 = (((float *)X)[2 * (ix)]);
    const float x_imag1 = (((float *)X)[2 * (ix) + 1]);
    (((float *)X)[2 * (ix)]) = x_real1 * alpha_real - x_imag1 * alpha_imag;
    (((float *)X)[2 * (ix) + 1]) = x_real1 * alpha_imag + x_imag1 * alpha_real;

    if (ix + incX < N * incX) {
        const int ix_next = ix + incX;
        const float x_real2 = (((float *)X)[2 * (ix_next)]);
        const float x_imag2 = (((float *)X)[2 * (ix_next) + 1]);
        (((float *)X)[2 * (ix_next)]) = x_real2 * alpha_real - x_imag2 * alpha_imag;
        (((float *)X)[2 * (ix_next) + 1]) = x_real2 * alpha_imag + x_imag2 * alpha_real;
    }
    ix += 2 * incX;
}
}
