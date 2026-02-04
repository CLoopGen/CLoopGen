#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1 * n2; i++) {
    const int idx = i % n2;
    const int idy = i / n2;
    const ptrdiff_t offset = 2 * (ldb * idy + idx);
    const double *base = (const double *)B;
    double Bij_real = base[offset];
    double Bij_imag = base[offset + 1];
    ((double *)B)[offset] = alpha_real * Bij_real - alpha_imag * Bij_imag;
    ((double *)B)[offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
}
}
