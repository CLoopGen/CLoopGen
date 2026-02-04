#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int ii, jj;
for (ii = 0; ii < N; ii++) {
    for (jj = 0; jj < N; jj++) {
        if (jj >= ii) {
            const float Cij_real = (((float *)C)[2 * (ldc * ii + jj)]);
            const float Cij_imag = (((float *)C)[2 * (ldc * ii + jj) + 1]);
            (((float *)C)[2 * (ldc * ii + jj)]) = beta_real * Cij_real - beta_imag * Cij_imag;
            (((float *)C)[2 * (ldc * ii + jj) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
