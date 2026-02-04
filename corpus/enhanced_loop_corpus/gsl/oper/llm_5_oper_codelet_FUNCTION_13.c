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
            if (j > i) {
                const size_t aij = 2 * (i * tda_a + j);
                const size_t bij = 2 * (i * tda_b + j);
            }
        }
    }
}
