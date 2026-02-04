#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        int base_idx = ldc * i;
        double temp_real, temp_imag;
        for (j = i; j < N; j++) {
            int offset = 2 * (base_idx + j);
            temp_real = C_ptr[offset];
            temp_imag = C_ptr[offset + 1];
            C_ptr[offset]     = beta_real * temp_real - beta_imag * temp_imag;
            C_ptr[offset + 1] = beta_real * temp_imag + beta_imag * temp_real;
        }
    }
}
