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
    const int idx_i = i / n2;
    const int idx_j = i % n2;
    const double Bij_real = (((double *)B)[2 * (ldb * idx_i + idx_j)]);
    const double Bij_imag = (((double *)B)[2 * (ldb * idx_i + idx_j) + 1]);
    (((double *)B)[2 * (ldb * idx_i + idx_j)]) = alpha_real * Bij_real - alpha_imag * Bij_imag;
    (((double *)B)[2 * (ldb * idx_i + idx_j) + 1]) = alpha_real * Bij_imag + alpha_imag * Bij_real;
}
}
