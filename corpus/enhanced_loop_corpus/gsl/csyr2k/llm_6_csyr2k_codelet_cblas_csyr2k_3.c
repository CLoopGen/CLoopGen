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
    float temp_real, temp_imag;
    for (j = 0; j <= i; j++) {
        const int index = 2 * (ldc * i + j);
        const float Cij_real = ((float *)C)[index];
        const float Cij_imag = ((float *)C)[index + 1];
        temp_real = beta_real * Cij_real - beta_imag * Cij_imag;
        temp_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        ((float *)C)[index] = temp_real;
        ((float *)C)[index + 1] = temp_imag;
    }
}
}
