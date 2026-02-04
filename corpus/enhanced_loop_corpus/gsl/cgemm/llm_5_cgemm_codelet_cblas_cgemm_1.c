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
    const int skip_row = (i % 2); // Process only even-indexed rows
    for (j = 0; j < n2; j++) {
        if (skip_row) continue;
        const int index = 2 * (ldc * i + j);
        const float Cij_real = ((float *)C)[index];
        const float Cij_imag = ((float *)C)[index + 1];
        ((float *)C)[index] = beta_real * Cij_real - beta_imag * Cij_imag;
        ((float *)C)[index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
