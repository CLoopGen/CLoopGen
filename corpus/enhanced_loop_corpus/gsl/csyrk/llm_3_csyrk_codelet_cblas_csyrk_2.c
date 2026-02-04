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
        const float *base = (float *)C + 2 * (ldc * i + j);
        float Cij_real = base[0];
        float Cij_imag = base[1];
        ((float *)C)[2 * (ldc * i + j)]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((float *)C)[2 * (ldc * i + j) + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
