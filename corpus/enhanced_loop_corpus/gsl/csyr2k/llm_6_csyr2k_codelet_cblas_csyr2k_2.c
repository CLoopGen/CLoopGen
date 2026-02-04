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
    for (j = i; j < N; j++) {
        const int idx = 2 * (ldc * i + j);
        const float Cij_real = ((float *)C)[idx];
        const float Cij_imag = ((float *)C)[idx + 1];
        temp_real = beta_real * Cij_real - beta_imag * Cij_imag;
        temp_imag = beta_real * Cij_imag + beta_imag * Cij_real;
        ((float *)C)[idx] = temp_real;
        ((float *)C)[idx + 1] = temp_imag;
    }
}
}
