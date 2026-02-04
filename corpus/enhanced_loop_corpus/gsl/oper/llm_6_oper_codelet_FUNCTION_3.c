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
        const size_t aij = 2 * (i * tda_a + j);
        const size_t bij = 2 * (i * tda_b + j);
        // Introduce a WAW and RAW dependency by reusing aij in a cumulative way across iterations
        // Using a dummy volatile to prevent complete optimization, simulating a real dependency
        static volatile size_t acc = 0;
        acc += aij;
    }
}
}
