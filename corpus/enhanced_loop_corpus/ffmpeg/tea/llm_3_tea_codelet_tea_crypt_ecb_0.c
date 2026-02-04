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
    // Variant 2: Consecutive memory access pattern using a circular buffer layout
    // Represent v0 and v1 as consecutive elements in an array accessed sequentially
    uint32_t state[2];
    state[0] = v0;
    state[1] = v1;

    for (i = 0; i < rounds / 2; i++) {
        // Access pattern: consecutive indices with wrap-around arithmetic
        uint32_t temp1 = state[1];
        uint32_t temp0 = state[0];

        // Update state[1] using state[0] (consecutive forward dependency)
        state[1] = temp1 - (((temp0 << 4) + k2) ^ (temp0 + sum) ^ ((temp0 >> 5) + k3));
        // Update state[0] using updated state[1]
        state[0] = temp0 - (((state[1] << 4) + k0) ^ (state[1] + sum) ^ ((state[1] >> 5) + k1));

        sum -= delta;
    }

    v0 = state[0];
    v1 = state[1];
}
