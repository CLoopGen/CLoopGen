#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coefficients[64];
extern short *block;
extern unsigned int i;
extern unsigned int j;
extern unsigned int k;
extern double out[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing via Pointer Arithmetic
    // Replace direct indexing with pointer arithmetic and introduce a strided access pattern
    // using precomputed pointers to simulate non-unit stride for coefficients and block data.

    for (i = 0; i < 64; i += 8) {
        double *coeff_ptr = coefficients + i;
        short *block_base = block;
        double *out_ptr = out + i;

        for (j = 0; j < 8; ++j) {
            double tmp = 0;
            short *block_ptr = block_base + j; // Start at column j, step by 8 (row stride)
            for (k = 0; k < 8; ++k) {
                tmp += coeff_ptr[k] * block_ptr[0]; // block_ptr points into column j, row k
                block_ptr += 8; // Stride by 8 to next row in same column (strided access)
            }
            out_ptr[j] = tmp * 8;
        }
    }
}
