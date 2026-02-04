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
    // Variant 2: Strided memory access — traverse columns first with explicit stride over rows (j-major order)
    double *C_base = (double *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const int linear_index = ldc * i + j;
            const int offset = 2 * linear_index;
            const double Cij_real = C_base[offset];
            const double Cij_imag = C_base[offset + 1];
            C_base[offset]         = beta_real * Cij_real - beta_imag * Cij_imag;
            C_base[offset + 1]     = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
