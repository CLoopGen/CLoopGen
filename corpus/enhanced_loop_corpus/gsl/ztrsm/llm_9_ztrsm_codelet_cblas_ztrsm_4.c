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
    // Variant 2: Reduced computational intensity with modified trip count and fused outer loop
    // Only process every second row and column to reduce total iterations by ~75%
    // Also fuse both loops into a single loop using linear indexing for reduced nesting overhead
    const int stride = ldb * 2; // Skip one row
    const int step = 2;         // Skip one column
    const int effective_n1 = (n1 + 1) / 2;
    const int effective_n2 = (n2 + 1) / 2;
    const int total_iters = effective_n1 * effective_n2;

    for (int idx = 0; idx < total_iters; idx++) {
        int ii = idx / effective_n2; // mapped to original i index
        int jj = idx % effective_n2; // mapped to original j index

        // Map to actual indices in B: every second row and column
        int i_actual = 2 * ii;
        int j_actual = 2 * jj;

        if (i_actual < n1 && j_actual < n2) {
            const double Bij_real = (((double *)B)[2 * (ldb * i_actual + j_actual)]);
            const double Bij_imag = (((double *)B)[2 * (ldb * i_actual + j_actual) + 1]);

            (((double *)B)[2 * (ldb * i_actual + j_actual)]) = 
                alpha_real * Bij_real - alpha_imag * Bij_imag;
            (((double *)B)[2 * (ldb * i_actual + j_actual) + 1]) = 
                alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
