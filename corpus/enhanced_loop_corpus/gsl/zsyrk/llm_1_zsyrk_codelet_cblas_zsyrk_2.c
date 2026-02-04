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
    for (j = 0; j < N; j++) {
        if (j >= i) {
            const int idx = 2 * (ldc * i + j);
            const double Cij_real = ((double *)C)[idx];
            const double Cij_imag = ((double *)C)[idx + 1];
            ((double *)C)[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            ((double *)C)[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
