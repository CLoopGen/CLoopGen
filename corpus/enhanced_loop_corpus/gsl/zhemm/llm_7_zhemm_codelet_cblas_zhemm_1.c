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
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *C_ptr = (double *)C;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = ldc * i + j;
            int offset = 2 * idx;
            double temp_real = C_ptr[offset];
            double temp_imag = C_ptr[offset + 1];
            double result_real = beta_real * temp_real - beta_imag * temp_imag;
            double result_imag = beta_real * temp_imag + beta_imag * temp_real;
            C_ptr[offset]     = result_real;
            C_ptr[offset + 1] = result_imag;
        }
    }
}
