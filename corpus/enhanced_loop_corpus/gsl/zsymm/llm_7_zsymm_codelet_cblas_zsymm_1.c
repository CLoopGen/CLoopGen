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
    // Reverse loop order to change loop-carried dependency direction (still valid since no cross-iteration computation)
    for (i = n1 - 1; i >= 0; i--) {
        for (j = n2 - 1; j >= 0; j--) {
            int idx = 2 * (ldc * i + j);
            double Cij_real = C_ptr[idx];
            double Cij_imag = C_ptr[idx + 1];
            // Use in-place update with fused multiply-add style pattern (same semantics)
            // This preserves data flow but changes instruction-level dependencies slightly
            C_ptr[idx] = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
