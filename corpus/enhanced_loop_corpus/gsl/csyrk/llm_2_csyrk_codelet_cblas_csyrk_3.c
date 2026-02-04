#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float *base_C = &((float *)C)[2 * ldc * i];
    for (j = 0; j <= i; j++) {
        const float Cij_real = base_C[2 * j];
        const float Cij_imag = base_C[2 * j + 1];
        base_C[2 * j]     = beta_real * Cij_real - beta_imag * Cij_imag;
        base_C[2 * j + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
