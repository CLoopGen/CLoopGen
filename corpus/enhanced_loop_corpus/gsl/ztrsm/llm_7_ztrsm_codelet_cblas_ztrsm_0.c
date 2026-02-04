#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *B_ptr = (double *)B;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldb * i + j);
            double temp_real = B_ptr[idx];
            double temp_imag = B_ptr[idx + 1];
            // Introduce artificial loop-carried dependency on a local variable (WAW-like pattern within scope)
            double accum_real = temp_real;
            double accum_imag = temp_imag;
            accum_real = alpha_real * accum_real - alpha_imag * accum_imag;
            accum_imag = alpha_real * temp_imag + alpha_imag * temp_real;  // Use original to break cyclic dep
            B_ptr[idx]     = accum_real;
            B_ptr[idx + 1] = accum_imag;
        }
    }
}
