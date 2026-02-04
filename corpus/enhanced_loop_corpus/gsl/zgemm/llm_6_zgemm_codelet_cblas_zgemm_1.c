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
        int base_idx = 2 * ldc * i;
        for (j = 0; j < n2; j++) {
            int offset = base_idx + 2 * j;
            double Cij_real = C_ptr[offset];
            double Cij_imag = C_ptr[offset + 1];
            // Introduce temporary accumulation (WAW dependency within the same iteration, no loop-carried)
            double temp_real = beta_real * Cij_real - beta_imag * Cij_imag;
            double temp_imag = beta_real * Cij_imag + beta_imag * Cij_real;
            C_ptr[offset] = temp_real;
            C_ptr[offset + 1] = temp_imag;
        }
    }
}
