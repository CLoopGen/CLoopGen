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
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with column-major traversal
    // This variant changes the loop nesting and access pattern to walk down columns first
    float *C_ptr = (float *)C;
    const int total_rows_float = ldc * 2;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int idx = j * 2 + i * total_rows_float; // Column-major indexing in complex layout
            const float Cij_real = C_ptr[idx];
            const float Cij_imag = C_ptr[idx + 1];
            C_ptr[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
