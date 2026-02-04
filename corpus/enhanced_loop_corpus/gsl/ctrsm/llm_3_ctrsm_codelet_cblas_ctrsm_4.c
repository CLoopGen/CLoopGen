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
    // Variant 2: Strided memory access with explicit pointer arithmetic and fixed increment per row
    float *base = (float *)B;
    for (i = 0; i < n1; i++) {
        float *row_start = base + 2 * ldb * i;
        for (j = 0; j < n2; j++) {
            float *Bij = row_start + 2 * j;
            const float Bij_real = Bij[0];
            const float Bij_imag = Bij[1];
            Bij[0] = alpha_real * Bij_real - alpha_imag * Bij_imag;
            Bij[1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
