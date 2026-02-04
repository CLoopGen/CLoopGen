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
const int stride = ldb * 2;
for (i = 0; i < n1; i++) {
    int base_idx = 2 * ldb * i;
    for (j = 0; j < n2; j++) {
        int idx = base_idx + 2 * j;
        double temp_real = (((double *)B)[idx]);
        double temp_imag = (((double *)B)[idx + 1]);

        ((double*)B)[idx]     = alpha_real * temp_real;
        ((double*)B)[idx + 1] = alpha_real * temp_imag;

        ((double*)B)[idx]     -= alpha_imag * temp_imag;
        ((double*)B)[idx + 1] += alpha_imag * temp_real;
    }
    base_idx += stride;
}
}
