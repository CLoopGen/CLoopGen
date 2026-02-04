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
for (i = 0; i < n1; i += 2) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            const double Cij_real = (((double *)C)[2 * (ldc * i + j)]);
            const double Cij_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
            const double Ci1j_real = (((double *)C)[2 * (ldc * (i + 1) + j)]);
            const double Ci1j_imag = (((double *)C)[2 * (ldc * (i + 1) + j) + 1]);

            (((double *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
            (((double *)C)[2 * (ldc * (i + 1) + j)]) = beta_real * Ci1j_real - beta_imag * Ci1j_imag;
            (((double *)C)[2 * (ldc * (i + 1) + j) + 1]) = beta_real * Ci1j_imag + beta_imag * Ci1j_real;
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
