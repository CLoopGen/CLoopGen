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
    // Variant 2: Strided memory access — traverse column-major with explicit striding over complex elements
    double *C_base = (double *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int offset = ldc * i + j;
            int real_idx = 2 * offset;
            int imag_idx = 2 * offset + 1;
            const double Cij_real = C_base[real_idx];
            const double Cij_imag = C_base[imag_idx];
            C_base[real_idx] = beta_real * Cij_real - beta_imag * Cij_imag;
            C_base[imag_idx] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
