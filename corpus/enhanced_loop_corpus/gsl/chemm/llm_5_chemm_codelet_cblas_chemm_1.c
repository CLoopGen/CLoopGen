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
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    const int skip_row = (beta_real == 0.0f && beta_imag == 0.0f);
    if (skip_row) continue;
    for (j = 0; j < n2; j++) {
        const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
        const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
        float result_real, result_imag;
        if (beta_imag == 0.0f) {
            result_real = beta_real * Cij_real;
            result_imag = beta_real * Cij_imag;
        } else {
            result_real = beta_real * Cij_real - beta_imag * Cij_imag;
            result_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        }
        (((float *)C)[2 * (ldc * i + j)]) = result_real;
        (((float *)C)[2 * (ldc * i + j) + 1]) = result_imag;
    }
}
}
