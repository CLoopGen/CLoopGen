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
const int stride = (ldc << 1);
int index = 0;
for (i = 0; i < n1; i++) {
    index = 2 * ldc * i;
    for (j = 0; j < n2; j++) {
        const double Cij_real = ((double *)C)[index];
        const double Cij_imag = ((double *)C)[index + 1];
        ((double *)C)[index]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((double *)C)[index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        index += 2;
    }
}
}
