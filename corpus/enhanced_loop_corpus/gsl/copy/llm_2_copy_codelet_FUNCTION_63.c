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
    // Variant 1: Consecutive memory access pattern using a single index with stride simulation
    size_t idx;
    for (i = 1; i < M; i++) {
        size_t limit = (i < N) ? i : N;
        for (idx = 0; idx < limit; idx += 1) {
            // Simulate consecutive access by treating iteration as linear memory traversal
            // This could map to array[idx] in a flattened buffer
        }
    }
}
