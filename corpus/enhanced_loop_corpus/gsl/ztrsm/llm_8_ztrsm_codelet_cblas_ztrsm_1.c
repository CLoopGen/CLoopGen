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
    for (j = 0; j < n2; j += 2) {
        if (j + 1 < n2) {
            const double Bij0_real = (((double *)B)[2 * (ldb * i + j)]);
            const double Bij0_imag = (((double *)B)[2 * (ldb * i + j) + 1]);
            const double Bij1_real = (((double *)B)[2 * (ldb * i + j + 1)]);
            const double Bij1_imag = (((double *)B)[2 * (ldb * i + j + 1) + 1]);

            (((double *)B)[2 * (ldb * i + j)])     = alpha_real * Bij0_real - alpha_imag * Bij0_imag;
            (((double *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij0_imag + alpha_imag * Bij0_real;
            (((double *)B)[2 * (ldb * i + j + 1)])     = alpha_real * Bij1_real - alpha_imag * Bij1_imag;
            (((double *)B)[2 * (ldb * i + j + 1) + 1]) = alpha_real * Bij1_imag + alpha_imag * Bij1_real;
        } else {
            const double Bij_real = (((double *)B)[2 * (ldb * i + j)]);
            const double Bij_imag = (((double *)B)[2 * (ldb * i + j) + 1]);
            (((double *)B)[2 * (ldb * i + j)]) = alpha_real * Bij_real - alpha_imag * Bij_imag;
            (((double *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
}
