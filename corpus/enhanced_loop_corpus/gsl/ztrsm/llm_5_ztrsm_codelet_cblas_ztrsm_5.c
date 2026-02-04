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
    const int skip = (i % 3 == 0) ? 1 : 0;
    for (j = skip; j < n2; j++) {
        const int index = 2 * (ldb * i + j);
        const double Bij_real = ((double *)B)[index];
        const double Bij_imag = ((double *)B)[index + 1];
        const double temp_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        ((double *)B)[index] = temp_real;
        ((double *)B)[index + 1] = temp_imag;
    }
}
}
