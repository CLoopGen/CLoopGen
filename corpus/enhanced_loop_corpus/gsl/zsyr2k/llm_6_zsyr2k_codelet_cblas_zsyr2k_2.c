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
    double temp_real, temp_imag;
    for (j = i; j < N; j++) {
        const int index = 2 * (ldc * i + j);
        const double Cij_real = ((double *)C)[index];
        const double Cij_imag = ((double *)C)[index + 1];
        temp_real = beta_real * Cij_real - beta_imag * Cij_imag;
        temp_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        ((double *)C)[index] = temp_real;
        ((double *)C)[index + 1] = temp_imag;
    }
}
}
