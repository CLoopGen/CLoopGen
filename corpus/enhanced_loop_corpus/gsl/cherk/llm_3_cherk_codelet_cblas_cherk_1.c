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
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid linear indices using indirect addressing to simulate irregular access
    // This mimics scenarios where access patterns are data-dependent or precomputed.
    int *indices = (int*)malloc(sizeof(int) * N * (N + 1) / 2 * 2); // Max size needed
    int idx_count = 0;
    for (int ii = 0; ii < N; ii++) {
        for (int jj = 0; jj <= ii; jj++) {
            int base_offset = 2 * (ldc * ii + jj);
            indices[idx_count++] = base_offset;
            indices[idx_count++] = base_offset + 1;
        }
    }
    float *C_ptr = (float *)C;
    for (int k = 0; k < idx_count; k++) {
        C_ptr[indices[k]] = 0.;
    }
    free(indices);
}
