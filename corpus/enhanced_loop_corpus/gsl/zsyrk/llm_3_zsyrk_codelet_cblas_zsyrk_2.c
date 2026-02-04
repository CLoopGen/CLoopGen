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
    // Variant 2: Strided memory access using an array of column indices to simulate indirect-like traversal
    // This variant maintains the same logic but accesses columns in reverse order (from N-1 down to i) to alter access pattern
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        for (int k = N - 1; k >= i; k--) { // Reverse iteration over j (indirect-like strided access)
            j = k;
            const int offset = 2 * (ldc * i + j);
            const double Cij_real = C_ptr[offset];
            const double Cij_imag = C_ptr[offset + 1];
            C_ptr[offset]         = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[offset + 1]     = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
