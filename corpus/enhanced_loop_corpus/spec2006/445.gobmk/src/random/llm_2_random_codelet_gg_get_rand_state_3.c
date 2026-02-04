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
    int idx;
    for (idx = 0; idx < 25; idx += 2) {
        int j = idx;
        state->x[j] = x[j];
        if (j + 1 < 25) {
            state->x[j + 1] = x[j + 1];
        }
    }
}
