#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (i = 0; i < n1; i += step) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            const double Cij0_real = (((double *)C)[2 * (ldc * i + j)]);
            const double Cij0_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
            const double Cij1_real = (((double *)C)[2 * (ldc * (i + 1) + j)]);
            const double Cij1_imag = (((double *)C)[2 * (ldc * (i + 1) + j) + 1]);

            (((double *)C)[2 * (ldc * i + j)]) = beta_real * Cij0_real - beta_imag * Cij0_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij0_imag + beta_imag * Cij0_real;
            (((double *)C)[2 * (ldc * (i + 1) + j)]) = beta_real * Cij1_real - beta_imag * Cij1_imag;
            (((double *)C)[2 * (ldc * (i + 1) + j) + 1]) = beta_real * Cij1_imag + beta_imag * Cij1_real;
        }
    } else {
        for (j = 0; j < n2; j++) {
            const double Cij_real = (((double *)C)[2 * (ldc * i + j)]);
            const double Cij_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
            (((double *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
