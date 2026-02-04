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
    double *base_C = (double *)C + 2 * ldc * i;
    for (j = 0; j <= i; j++) {
        const double Cij_real = base_C[2 * j];
        const double Cij_imag = base_C[2 * j + 1];
        base_C[2 * j] = beta_real * Cij_real - beta_imag * Cij_imag;
        base_C[2 * j + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
