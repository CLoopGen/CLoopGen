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
for (i = 0; i < N; i += 2) {
    for (j = 0; j <= i; j++) {
        const int idx_ij = 2 * (ldc * i + j);
        const float Cij_real = ((float *)C)[idx_ij];
        const float Cij_imag = ((float *)C)[idx_ij + 1];
        ((float *)C)[idx_ij]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((float *)C)[idx_ij + 1] = beta_real * Cij_imag + beta_imag * Cij_real;

        if (i + 1 < N) {
            const int idx_next = 2 * (ldc * (i + 1) + j);
            const float C_next_real = ((float *)C)[idx_next];
            const float C_next_imag = ((float *)C)[idx_next + 1];
            ((float *)C)[idx_next]     = beta_real * C_next_real - beta_imag * C_next_imag;
            ((float *)C)[idx_next + 1] = beta_real * C_next_imag + beta_imag * C_next_real;
        }
    }
}
}
