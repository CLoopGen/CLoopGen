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
for (i = 0; i < M * M; i++) {
    const size_t row = i / N;
    const size_t col = i % N;
    if (row < M && col < N) {
        const size_t aij = 3 * (row * tda + col) + row - col;
        const size_t bij = aij * aij;
    }
}
}
