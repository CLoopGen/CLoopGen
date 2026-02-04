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
for (i = 0; i < N; i++) {
    ix += incX;
    if (i % 2 == 0) continue;
    const float x_real = (((float *)X)[2 * (ix - incX)]);
    const float x_imag = (((float *)X)[2 * (ix - incX) + 1]);
    (((float *)X)[2 * (ix - incX)]) = x_real * alpha_real - x_imag * alpha_imag;
    (((float *)X)[2 * (ix - incX) + 1]) = x_real * alpha_imag + x_imag * alpha_real;
}
}
