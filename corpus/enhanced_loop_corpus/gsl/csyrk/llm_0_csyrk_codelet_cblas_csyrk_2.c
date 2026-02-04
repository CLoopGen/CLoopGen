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
    const int offset_i = ldc * i;
    for (j = i; j < N; j++) {
        const int idx = 2 * (offset_i + j);
        float *Cptr = (float *)C;
        const float Cij_real = Cptr[idx];
        const float Cij_imag = Cptr[idx + 1];
        Cptr[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
