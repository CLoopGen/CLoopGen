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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const double Cij_real = (((double *)C)[2 * (ldc * i + j)]);
        const double Cij_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
        double result_real, result_imag;

        if (beta_real == 1.0 && beta_imag == 0.0) {
            result_real = Cij_real;
            result_imag = Cij_imag;
        } else {
            result_real = beta_real * Cij_real - beta_imag * Cij_imag;
            result_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        }

        (((double *)C)[2 * (ldc * i + j)]) = result_real;
        (((double *)C)[2 * (ldc * i + j) + 1]) = result_imag;
    }
}
}
