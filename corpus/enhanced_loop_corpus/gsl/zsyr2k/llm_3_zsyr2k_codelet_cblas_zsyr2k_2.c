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
const double *C_const = (const double *)C;
double *C_ptr = (double *)C;
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        const int idx = 2 * (ldc * i + j);
        const double Cij_real = C_const[idx];
        const double Cij_imag = C_const[idx + 1];
        C_ptr[idx] = beta_real * Cij_real - beta_imag * Cij_imag;
        C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
