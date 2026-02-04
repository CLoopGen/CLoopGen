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
    for (pos = 0; pos < 624; pos += 3) {
        state->key[pos] = seed;
        if (pos + 1 < 624) {
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 1) & 4294967295UL;
            state->key[pos + 1] = seed;
        }
        if (pos + 2 < 624) {
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 2) & 4294967295UL;
            state->key[pos + 2] = seed;
        }
        seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 3) & 4294967295UL;
    }
}
