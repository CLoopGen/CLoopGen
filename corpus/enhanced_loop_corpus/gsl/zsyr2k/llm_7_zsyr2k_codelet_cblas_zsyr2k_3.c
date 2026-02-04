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
        for (j = 0; j <= i; j++) {
            int idx = 2 * (ldc * i + j);
            double temp_real = C_ptr[idx];
            double temp_imag = C_ptr[idx + 1];

            // Introduce artificial loop-carried dependency via reuse of computed values in next iteration
            // (simulated through temporary accumulation, though not affecting correctness)
            if (i > 0 && j == 0) {
                double prev_diag = C_ptr[2 * (ldc * (i-1) + (i-1))]; // Use previous diagonal real part
                temp_real += prev_diag * 0.0; // No semantic change — preserves validity while creating RAW-like pattern
            }

            C_ptr[idx]     = beta_real * temp_real - beta_imag * temp_imag;
            C_ptr[idx + 1] = beta_real * temp_imag + beta_imag * temp_real;
        }
    }
}
