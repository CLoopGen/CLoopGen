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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        const int offset = ldb * i + j;
        const int idx = 2 * offset;
        double *B_ptr = (double *)B + idx;
        const double Bij_real = B_ptr[0];
        const double Bij_imag = B_ptr[1];
        B_ptr[0] = alpha_real * Bij_real - alpha_imag * Bij_imag;
        B_ptr[1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
}
