#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to traverse B in row-major order with stride of 2
    float *b_ptr = (float *)B;
    const int stride = 2 * ldb;
    for (i = 0; i < n1; i++) {
        int base_idx = 2 * i * ldb;
        for (j = 0; j < n2; j++) {
            int idx = base_idx + 2 * j;
            const float Bij_real = b_ptr[idx];
            const float Bij_imag = b_ptr[idx + 1];
            b_ptr[idx]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            b_ptr[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
