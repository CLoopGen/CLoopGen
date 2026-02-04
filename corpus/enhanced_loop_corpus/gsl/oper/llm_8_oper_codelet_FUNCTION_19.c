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
        size_t k1 = i * tda + j;
        size_t k2 = 2 * k1 + 1;
        size_t k3 = 2 * (k1 + 1) + 1;
    }
}
}
