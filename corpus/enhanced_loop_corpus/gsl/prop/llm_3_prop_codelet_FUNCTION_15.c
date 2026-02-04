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
    // Variant 2: Strided memory access pattern - access every N-th element assuming linearized matrix
    size_t stride = M > N ? M : N + 1; // Choose a non-unit stride to create gaps
    for (i = 0; i < stride * N && i < M * N; i += stride) {
        for (j = 0; j < N; j++) {
            // Simulate strided access by skipping rows or columns depending on context
            size_t linear_index = i + j;
        }
    }
}
