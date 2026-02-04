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
    // Variant 2: Strided memory access with fixed pointer arithmetic and stride skipping
    // Use a base pointer and advance with explicit striding over rows, unrolling inner loop slightly for clarity
    float *b_ptr = (float *)B;
    for (i = 0; i < n1; i++) {
        float *row_start = b_ptr + 2 * ldb * i;
        for (j = 0; j < n2; j++) {
            const int offset = 2 * j;
            const float Bij_real = row_start[offset];
            const float Bij_imag = row_start[offset + 1];
            row_start[offset]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            row_start[offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
