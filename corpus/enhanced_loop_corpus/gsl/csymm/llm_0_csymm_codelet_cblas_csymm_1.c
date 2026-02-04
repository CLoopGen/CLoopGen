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
    const int offset_i = ldc * i;
    for (j = 0; j < n2; j++) {
        const int idx = 2 * (offset_i + j);
        const float Cij_real = ((float *)C)[idx];
        const float Cij_imag = ((float *)C)[idx + 1];
        ((float *)C)[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
        ((float *)C)[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
