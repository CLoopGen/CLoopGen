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
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        const float* base = (float*)C;
        const int idx = 2 * (ldc * i + j);
        const float Cij_real = base[idx];
        const float Cij_imag = base[idx + 1];
        ((float*)C)[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((float*)C)[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
