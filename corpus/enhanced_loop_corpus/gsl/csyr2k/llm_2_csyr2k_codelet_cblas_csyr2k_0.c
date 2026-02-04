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
    // Variant 1: Consecutive memory access by flattening the index and accessing elements in increasing order
    float *C_ptr = (float *)C;
    int total_elements = 2 * ldc * N;  // Assuming we're working within a band of the matrix
    for (i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i + 2 * i;  // Start of diagonal element in flattened layout
        for (j = i; j < N; j++) {
            int offset = 2 * (ldc * i + j);  // Original offset
            C_ptr[offset]     = 0.0f;
            C_ptr[offset + 1] = 0.0f;
        }
    }
}
