#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const int base_idx_i = ldc * i;
    for (j = i; j < N; j++) {
        const int idx = 2 * (base_idx_i + j);
        const double Cij_real = ((double *)C)[idx];
        const double Cij_imag = ((double *)C)[idx + 1];
        ((double *)C)[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((double *)C)[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
