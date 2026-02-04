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
    // Variant 2: Strided memory access - traverse the matrix column-wise with explicit striding to emphasize vertical access pattern
    float *B_float = (float *)B;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const int idx = 2 * (ldb * i + j);
            const float Bij_real = B_float[idx];
            const float Bij_imag = B_float[idx + 1];
            B_float[idx] = alpha_real * Bij_real - alpha_imag * Bij_imag;
            B_float[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
