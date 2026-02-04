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
    // Variant 2: Strided memory access pattern - access every K-th element across rows
    // Here we maintain the nested structure but modify access stride in the inner loop
    const size_t STRIDE = 4; // Example stride factor
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += STRIDE) {
            // Perform computation at strided intervals
            volatile size_t linear_idx = i * N + j; // Simulated strided access
            // This mimics accessing arr[i][j] with gaps in j
        }
    }
}
