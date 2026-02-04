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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        const int base_offset = 2 * (ldc * i + j);
        float* Cptr = (float*)C + base_offset;
        const float Cij_real = Cptr[0];
        const float Cij_imag = Cptr[1];
        Cptr[0] = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
