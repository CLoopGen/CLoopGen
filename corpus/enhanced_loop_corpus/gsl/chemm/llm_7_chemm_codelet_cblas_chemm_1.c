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
    float *C_ptr = (float *)C;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldc * i + j);
            float Cij_real = C_ptr[idx];
            float Cij_imag = C_ptr[idx + 1];
            float new_real = beta_real * Cij_real - beta_imag * Cij_imag;
            float new_imag = beta_real * Cij_imag + beta_imag * Cij_real;
            C_ptr[idx]     = new_real;
            C_ptr[idx + 1] = new_imag;
        }
    }
}
