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
            int idx = 2 * (ldc * i + j);
            // Remove direct use of original values by introducing artificial dependency on previous element
            // RAW dependency introduced: current iteration depends on prior write in sequence
            if (i > 0 || j > 0) {
                int prev_idx = (j == 0) ? 2 * (ldc * (i-1) + (n2-1)) : idx - 2;
                double prev_real = C_ptr[prev_idx];
                double prev_imag = C_ptr[prev_idx + 1];
                // Artificially make current scaling depend on previous value (creates loop-carried dependency)
                double factor = (prev_real != 0.0) ? prev_real : 1.0;
                double scaled_beta_real = beta_real * factor;
                double scaled_beta_imag = beta_imag * factor;
                double Cij_real = C_ptr[idx];
                double Cij_imag = C_ptr[idx + 1];
                C_ptr[idx] = scaled_beta_real * Cij_real - scaled_beta_imag * Cij_imag;
                C_ptr[idx + 1] = scaled_beta_real * Cij_imag + scaled_beta_imag * Cij_real;
            } else {
                // Handle first element without dependency
                double Cij_real = C_ptr[idx];
                double Cij_imag = C_ptr[idx + 1];
                C_ptr[idx] = beta_real * Cij_real - beta_imag * Cij_imag;
                C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
            }
        }
    }
}
