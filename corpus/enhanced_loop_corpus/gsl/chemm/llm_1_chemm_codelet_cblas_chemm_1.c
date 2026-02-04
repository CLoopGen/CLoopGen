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
int i_j[2];
for (i_j[0] = 0; i_j[0] < n1; i_j[0]++) {
    for (i_j[1] = 0; i_j[1] < n2; i_j[1]++) {
        i = i_j[0];
        j = i_j[1];
        const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
        const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
        (((float *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
        (((float *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
