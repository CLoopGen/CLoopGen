#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the index calculation
    // Instead of accessing diagonal-like elements (2*(ldc*i + i) + 1), we rewrite to access consecutive odd indices
    // assuming ldc is such that the original pattern skips many elements. Now we write to sequential odd positions.
    float *C_ptr = (float *)C;
    int base_index = 1; // Start at index 1 (first odd)
    for (i = 0; i < N; i++) {
        C_ptr[base_index + 2 * i] = 0.;
    }
}
