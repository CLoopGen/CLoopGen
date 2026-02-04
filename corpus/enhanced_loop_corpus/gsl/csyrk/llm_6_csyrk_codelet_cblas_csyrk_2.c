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
        int base_idx = 2 * ldc * i;
        float temp_real, temp_imag;
        for (j = i; j < N; j++) {
            int offset = base_idx + 2 * j;
            temp_real = C_ptr[offset];
            temp_imag = C_ptr[offset + 1];
            C_ptr[offset] = beta_real * temp_real - beta_imag * temp_imag;
            C_ptr[offset + 1] = beta_real * temp_imag + beta_imag * temp_real;
        }
    }
}
