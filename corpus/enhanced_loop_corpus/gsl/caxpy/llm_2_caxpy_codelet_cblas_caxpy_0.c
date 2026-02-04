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
    // Variant 1: Consecutive memory access with precomputed pointers and stride handling
    const float *x_ptr = (const float *)X;
    float *y_ptr = (float *)Y;
    const int x_stride = incX * 2; // Complex numbers: each element has real and imag (2 floats)
    const int y_stride = incY * 2;

    int x_idx = ix * 2;
    int y_idx = iy * 2;

    for (i = 0; i < N; i++) {
        const float x_real = x_ptr[x_idx];
        const float x_imag = x_ptr[x_idx + 1];

        y_ptr[y_idx]     += alpha_real * x_real - alpha_imag * x_imag;
        y_ptr[y_idx + 1] += alpha_real * x_imag + alpha_imag * x_real;

        x_idx += x_stride;
        y_idx += y_stride;
    }
}
