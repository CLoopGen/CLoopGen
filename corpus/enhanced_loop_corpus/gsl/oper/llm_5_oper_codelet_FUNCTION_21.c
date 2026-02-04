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
            const size_t index_a = i * tda_a + j;
            const size_t index_b = i * tda_b + j;
            if (index_a != index_b) {
                const size_t aij = 2 * index_a;
                const size_t bij = 2 * index_b;
            } else {
                continue;
            }
        }
    }
}
