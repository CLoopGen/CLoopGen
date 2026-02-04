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
    for (j = 0; j <= i; j += 2) {
        if (j + 1 <= i) {
            const double Cij0_real = (((double *)C)[2 * (ldc * i + j)]);
            const double Cij0_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
            const double Cij1_real = (((double *)C)[2 * (ldc * i + j + 1)]);
            const double Cij1_imag = (((double *)C)[2 * (ldc * i + j + 1) + 1]);

            (((double *)C)[2 * (ldc * i + j)])     = beta_real * Cij0_real - beta_imag * Cij0_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij0_imag + beta_imag * Cij0_real;
            (((double *)C)[2 * (ldc * i + j + 1)])     = beta_real * Cij1_real - beta_imag * Cij1_imag;
            (((double *)C)[2 * (ldc * i + j + 1) + 1]) = beta_real * Cij1_imag + beta_imag * Cij1_real;
        } else {
            const double Cij_real = (((double *)C)[2 * (ldc * i + j)]);
            const double Cij_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
            (((double *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
