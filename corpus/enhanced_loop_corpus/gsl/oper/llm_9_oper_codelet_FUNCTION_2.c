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
    const size_t offset_a = 2 * i * tda_a;
    const size_t offset_b = 2 * i * tda_b;
    for (j = 0; j < N; j++) {
        const size_t aij = offset_a + 2 * j;
        const size_t bij = offset_b + 2 * j;
    }
}
}
