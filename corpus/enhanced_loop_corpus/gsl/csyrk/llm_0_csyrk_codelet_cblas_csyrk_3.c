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
    const int temp_index = ldc * i;
    for (j = 0; j <= i; j++) {
        const int base_offset = 2 * (temp_index + j);
        float *Cptr = (float *)C;
        const float Cij_real = Cptr[base_offset];
        const float Cij_imag = Cptr[base_offset + 1];
        Cptr[base_offset]     = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[base_offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
