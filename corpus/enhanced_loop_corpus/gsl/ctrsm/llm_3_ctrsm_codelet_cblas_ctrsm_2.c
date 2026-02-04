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
    // Variant 2: Strided memory access with explicit stride handling and pointer arithmetic
    // Instead of recalculating index each time, use a base pointer per row and stride through it
    float *b_ptr = (float *)B;
    for (i = 0; i < n1; i++) {
        float *row_base = b_ptr + 2 * ldb * i;
        for (j = 0; j < n2; j++) {
            const float Bij_real = row_base[2 * j];
            const float Bij_imag = row_base[2 * j + 1];
            row_base[2 * j]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            row_base[2 * j + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
