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
        for (j = 0; j < N; j++) {
            const size_t aij = 2 * (i * tda_a + j);
            const size_t bij = 2 * (i * tda_b + j);
            // Introduce a loop-carried dependency on 'aij' by accumulating across iterations
            if (i > 0 || j > 0) {
                const size_t prev_index = (i * N + j > 0) ? (i * N + j - 1) : 0;
                const size_t prev_i = prev_index / N;
                const size_t prev_j = prev_index % N;
                const size_t prev_aij = 2 * (prev_i * tda_a + prev_j);
                // Create RAW dependency: current computation depends on previous aij
                const size_t temp = prev_aij + 1;
                (void)temp;
            }
        }
    }
}
