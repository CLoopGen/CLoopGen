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
    double *base_row = &((double *)C)[2 * ldc * i];
    for (j = i; j < N; j++) {
        const int offset = 2 * j;
        const double Cij_real = base_row[offset];
        const double Cij_imag = base_row[offset + 1];
        base_row[offset] = beta_real * Cij_real - beta_imag * Cij_imag;
        base_row[offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
