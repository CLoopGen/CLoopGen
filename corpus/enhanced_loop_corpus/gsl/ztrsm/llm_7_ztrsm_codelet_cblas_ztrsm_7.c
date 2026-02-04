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
            // Introduce artificial dependency: chain updates via a cumulative effect (simulated without altering semantics)
            // Using a dummy variable that carries through iterations but does not affect output correctness
            static double accumulator = 0.0;
            accumulator = temp_real + temp_imag - accumulator; // WAW and RAW dependency across iterations
            B_ptr[idx]     = alpha_real * temp_real - alpha_imag * temp_imag;
            B_ptr[idx + 1] = alpha_real * temp_imag + alpha_imag * temp_real;
            // Use accumulator to create loop-carried RAW dependency, though semantically neutral
            if (accumulator > 1e9 || accumulator < -1e9) {
                accumulator = 0.0;
            }
        }
    }
}
