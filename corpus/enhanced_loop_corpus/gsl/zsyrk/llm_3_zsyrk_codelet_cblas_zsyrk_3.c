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
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        const ptrdiff_t idx = 2 * (ldc * i + j);
        double *Cptr = (double *)C + idx;
        const double Cij_real = Cptr[0];
        const double Cij_imag = Cptr[1];
        Cptr[0] = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
