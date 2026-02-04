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
            float temp_real = C_ptr[idx];
            float temp_imag = C_ptr[idx + 1];
            float result_real = beta_real * temp_real - beta_imag * temp_imag;
            float result_imag = beta_real * temp_imag + beta_imag * temp_real;
            C_ptr[idx]     = result_real;
            C_ptr[idx + 1] = result_imag;
        }
    }
}
