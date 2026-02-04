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
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j++) {
        if (i + 1 < n1) {
            const float Cij0_real = (((float *)C)[2 * (ldc * i + j)]);
            const float Cij0_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
            const float Cij1_real = (((float *)C)[2 * (ldc * (i + 1) + j)]);
            const float Cij1_imag = (((float *)C)[2 * (ldc * (i + 1) + j) + 1]);

            (((float *)C)[2 * (ldc * i + j)]) = 0.5f * (beta_real * Cij0_real - beta_imag * Cij0_imag);
            (((float *)C)[2 * (ldc * i + j) + 1]) = 0.5f * (beta_real * Cij0_imag + beta_imag * Cij0_real);
            (((float *)C)[2 * (ldc * (i + 1) + j)]) = 0.5f * (beta_real * Cij1_real - beta_imag * Cij1_imag);
            (((float *)C)[2 * (ldc * (i + 1) + j) + 1]) = 0.5f * (beta_real * Cij1_imag + beta_imag * Cij1_real);
        } else {
            const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
            const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
            (((float *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
            (((float *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
