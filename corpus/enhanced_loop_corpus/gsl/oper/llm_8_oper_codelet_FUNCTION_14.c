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
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j += 2) {
        const size_t aij1 = i * tda + j;
        const size_t aij2 = aij1 * 2;
        const size_t aij3 = aij2 + 1;
        if (j + 1 < N) {
            const size_t aij4 = i * tda + (j + 1);
            const size_t aij5 = aij4 * 2;
        }
    }
}
}
