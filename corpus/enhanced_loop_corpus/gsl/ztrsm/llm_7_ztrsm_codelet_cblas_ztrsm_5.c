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
    double prev_real = 0.0, prev_imag = 0.0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldb * i + j);
            double curr_real = B_ptr[idx];
            double curr_imag = B_ptr[idx + 1];

            double scaled_real = alpha_real * curr_real - alpha_imag * curr_imag;
            double scaled_imag = alpha_real * curr_imag + alpha_imag * curr_real;

            if (i > 0 || j > 0) {
                scaled_real += prev_real;
                scaled_imag += prev_imag;
            }

            B_ptr[idx]     = scaled_real;
            B_ptr[idx + 1] = scaled_imag;

            prev_real = scaled_real;
            prev_imag = scaled_imag;
        }
    }
}
