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
    const size_t temp_i = 2 * i * tda;
    for (j = 0; j < N; j++) {
        const size_t aij = temp_i + 2 * j;
    }
}
}
