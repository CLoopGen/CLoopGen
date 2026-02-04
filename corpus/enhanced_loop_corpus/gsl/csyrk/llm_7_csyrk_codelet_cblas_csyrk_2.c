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
    float *C_ptr = (float *)C;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            int idx = 2 * (ldc * i + j);
            float Cij_real = C_ptr[idx];
            float Cij_imag = C_ptr[idx + 1];
            float result_real = beta_real * Cij_real - beta_imag * Cij_imag;
            float result_imag = beta_real * Cij_imag + beta_imag * Cij_real;
            C_ptr[idx] = result_real;
            C_ptr[idx + 1] = result_imag;
        }
    }
}
