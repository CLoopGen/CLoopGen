#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_accum = 0;
    for (i = 0; i < M; i++) {
        size_t row_sum = 0;
        for (j = 0; j < N; j++) {
            const size_t aij = 2 * (i * tda + j);
            row_sum += aij; // Local accumulation introduces intra-loop dependency (WAW on row_sum), but no loop-carried dependency across rows
        }
        local_accum += row_sum; // Reduce row_sum into local_accum, creating outer-loop dependency
    }
    // Ensure local_accum is used to prevent dead code elimination
    if (local_accum == 0) {
        local_accum = 1;
    }
}
