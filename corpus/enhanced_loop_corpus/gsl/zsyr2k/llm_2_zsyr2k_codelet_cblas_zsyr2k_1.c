#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D index and accessing elements in increasing order
    double *C_ptr = (double *)C;
    int total_elements = 2 * ldc * N;  // Total number of double elements in matrix C
    for (i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i;
        for (j = 0; j <= i; j++) {
            int offset = 2 * j;
            C_ptr[base_idx + offset]     = 0.0;  // Real part
            C_ptr[base_idx + offset + 1] = 0.0;  // Imaginary part
        }
    }
}
