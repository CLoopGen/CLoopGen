#include <stdio.h>

#include <inttypes.h>

struct gg_rand_state {
    unsigned int x[25];
    int k;
};


extern unsigned int x[25];
extern struct gg_rand_state *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle pairs
    for (i = 0; i < 25; i += 2) {
        if (i + 1 < 25) {
            x[i]     = state->x[i];
            x[i + 1] = state->x[i + 1];
        } else {
            x[i] = state->x[i];
        }
    }
}
