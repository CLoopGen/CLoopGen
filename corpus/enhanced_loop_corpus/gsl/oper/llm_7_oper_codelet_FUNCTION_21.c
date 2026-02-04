#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda_a;
extern  size_t tda_b;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M; i++) {
        size_t local_sum_a = 0;
        size_t local_sum_b = 0;
        for (j = 0; j < N; j++) {
            const size_t aij = 2 * (i * tda_a + j);
            const size_t bij = 2 * (i * tda_b + j);
            local_sum_a += aij; // Local reduction: no loop-carried dependency across 'i', but intra-loop dependency
            local_sum_b += bij;
        }
        // Use local sums to break inter-iteration dependencies across 'i' — privatization of reduction variables
        const size_t row_total = local_sum_a + local_sum_b;
    }
    // Eliminated cross-iteration state; all dependencies are confined within outer loop body
}
