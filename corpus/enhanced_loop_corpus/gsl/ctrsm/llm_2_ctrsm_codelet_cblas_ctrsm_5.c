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
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing elements in a more cache-friendly, sequential manner
    float *B_float = (float *)B;
    const int stride = ldb * 2; // Stride in float units for row advancement
    for (i = 0; i < n1; i++) {
        float *row_base = &B_float[2 * i * ldb]; // Base of current row in B
        for (j = 0; j < n2; j++) {
            const float Bij_real = row_base[2 * j];
            const float Bij_imag = row_base[2 * j + 1];
            row_base[2 * j] = alpha_real * Bij_real - alpha_imag * Bij_imag;
            row_base[2 * j + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
