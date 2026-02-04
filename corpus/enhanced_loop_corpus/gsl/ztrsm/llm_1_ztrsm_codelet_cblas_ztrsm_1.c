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
for (i = 0; i < n1; i++) {
    const int base_i = ldb * i;
    for (j = 0; j < n2; j++) {
        const int offset = 2 * (base_i + j);
        const double Bij_real = ((double *)B)[offset];
        const double Bij_imag = ((double *)B)[offset + 1];
        ((double *)B)[offset]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
        ((double *)B)[offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
}
