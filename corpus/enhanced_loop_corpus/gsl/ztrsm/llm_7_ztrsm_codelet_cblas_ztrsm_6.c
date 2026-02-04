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
            B_ptr[idx]     = alpha_real * temp_real - alpha_imag * temp_imag;
            // Introduce artificial loop-carried dependence by using previous iteration's result
            // in a temporary accumulation (simulating a reduction-like dependency)
            if (i > 0 || j > 0) {
                int prev_idx = (j == 0) ? 2*(ldb*(i-1) + (n2-1)) : idx - 2;
                B_ptr[idx] += B_ptr[prev_idx] * 0.001; // Weak WAW + RAW dependence across iterations
            }
            B_ptr[idx + 1] = alpha_real * temp_imag + alpha_imag * temp_real;
        }
    }
}
