#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

extern mt19937_state *state;
extern uint32_t seed;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling the loop to handle even and odd indices separately
    for (int i = 0; i < 312; i++) {
        int idx1 = i * 2;
        int idx2 = i * 2 + 1;
        state->key[idx1] = seed;
        uint32_t temp_seed = (1812433253UL * (seed ^ (seed >> 30)) + idx1 + 1) & 4294967295UL;
        if (idx2 < 624) {
            state->key[idx2] = temp_seed;
        }
        seed = (1812433253UL * (temp_seed ^ (temp_seed >> 30)) + idx2 + 1) & 4294967295UL;
    }
}
