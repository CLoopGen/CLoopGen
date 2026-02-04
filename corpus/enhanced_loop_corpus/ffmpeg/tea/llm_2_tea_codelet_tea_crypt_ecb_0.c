#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v0;
extern uint32_t v1;
extern int rounds;
extern uint32_t k0;
extern uint32_t k1;
extern uint32_t k2;
extern uint32_t k3;
extern int i;
extern uint32_t delta;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride of 2
    // We simulate strided access by treating v0 and v1 as elements of a logical array with non-consecutive access
    uint32_t *vec = (uint32_t*)malloc(2 * sizeof(uint32_t));
    vec[0] = v0;
    vec[1] = v1;

    for (i = 0; i < rounds / 2; i++) {
        // Stride-2 access pattern: alternate updates with offset arithmetic
        vec[(1 + 2*i) % 2] -= ((vec[(0 + 2*i) % 2] << 4) + k2) ^ (vec[(0 + 2*i) % 2] + sum) ^ ((vec[(0 + 2*i) % 2] >> 5) + k3);
        vec[(0 + 2*i) % 2] -= ((vec[(1 + 2*i) % 2] << 4) + k0) ^ (vec[(1 + 2*i) % 2] + sum) ^ ((vec[(1 + 2*i) % 2] >> 5) + k1);
        sum -= delta;
    }

    v0 = vec[0];
    v1 = vec[1];
    free(vec);
}
