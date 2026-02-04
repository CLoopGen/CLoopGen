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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
        const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
        const float temp_real = beta_real * Cij_real - beta_imag * Cij_imag;
        const float temp_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        (((float *)C)[2 * (ldc * i + j)]) = temp_real;
        (((float *)C)[2 * (ldc * i + j) + 1]) = temp_imag;
    }
}
}
