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
for (i = 0; i < M * N; i++) {
    const size_t idx = i % N;
    const size_t idy = i / N;
    if (idy < M) {
        const size_t aij = (idy * tda_a + idx) << 1;
        const size_t bij = (idy * tda_b + idx) << 1;
        const size_t temp1 = aij + bij;
        const size_t temp2 = aij ^ bij;
        const size_t temp3 = temp1 & temp2;
    }
}
}
