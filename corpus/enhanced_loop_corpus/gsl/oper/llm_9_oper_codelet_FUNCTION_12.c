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
        const size_t stride_a = 2 * tda_a;
        const size_t stride_b = 2 * tda_b;
        size_t aij_base = 0;
        size_t bij_base = 0;
        for (j = 0; j < N; j++) {
            const size_t aij = aij_base + 2 * j;
            const size_t bij = bij_base + 2 * j;
            aij_base += stride_a;
            bij_base += stride_b;
        }
    }
}
