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
for (i = 0; i < N; i++) {
    const float x_real = (((const float *)X)[2 * (ix)]);
    const float x_imag = (((const float *)X)[2 * (ix) + 1]);

    float temp_real = alpha_real * x_real - alpha_imag * x_imag;
    float temp_imag = alpha_real * x_imag + alpha_imag * x_real;

    // Additional computational workload: simulate a small filter-like accumulation
    for (int j = 0; j < 3; j++) {
        temp_real = temp_real * 0.9f + temp_imag * 0.1f;
        temp_imag = temp_imag * 0.9f - temp_real * 0.1f;
    }

    (((float *)Y)[2 * (iy)]) += temp_real;
    (((float *)Y)[2 * (iy) + 1]) += temp_imag;

    ix += incX;
    iy += incY;
}
}
