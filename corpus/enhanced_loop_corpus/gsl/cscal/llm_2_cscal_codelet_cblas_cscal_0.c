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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via ix, we assume X is accessed consecutively
    // Reset ix to base and treat X as a dense array of complex numbers (real, imag pairs)
    int idx = 0;
    float *x_ptr = (float *)X;
    for (i = 0; i < N; i++) {
        const float x_real = x_ptr[idx];
        const float x_imag = x_ptr[idx + 1];
        x_ptr[idx]     = x_real * alpha_real - x_imag * alpha_imag;
        x_ptr[idx + 1] = x_real * alpha_imag + x_imag * alpha_real;
        idx += 2; // Consecutive access: always move to next complex number
    }
}
