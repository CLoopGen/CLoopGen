#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern, traversing column-wise with stride M
    size_t *access_order = (size_t*)malloc(M * N * sizeof(size_t));
    if (!access_order) return; // Handle allocation failure
    size_t idx = 0;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            idx = j + i * N; // Original row-major logical index
            access_order[idx] = idx; // Simulate strided usage (could represent prefetching or reordering)
        }
    }
    free(access_order);
}
