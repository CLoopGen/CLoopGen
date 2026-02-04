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
    const int offset_i = ldc * i;
    for (j = 0; j <= i; j++) {
        const int index = 2 * (offset_i + j);
        double *Cptr = (double *)C;
        const double Cij_real = Cptr[index];
        const double Cij_imag = Cptr[index + 1];
        Cptr[index]     = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
