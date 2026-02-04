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
for (i = 0; i < M; i += 2) {
    for (j = 0; j < N; j += 2) {
        const size_t aij = 2 * (i * tda_a + j);
        const size_t bij = 2 * (i * tda_b + j);
        const size_t aij_next_j = 2 * (i * tda_a + j + 1);
        const size_t bij_next_j = 2 * (i * tda_b + j + 1);
        const size_t aij_next_i = 2 * ((i + 1) * tda_a + j);
        const size_t bij_next_i = 2 * ((i + 1) * tda_b + j);
        const size_t aij_next_ij = 2 * ((i + 1) * tda_a + j + 1);
        const size_t bij_next_ij = 2 * ((i + 1) * tda_b + j + 1);
    }
}
}
