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
    // Variant 1: Introduce loop-carried WAW dependency by splitting the loop into two phases
    // and introducing a write-after-write dependency on index 24.
    for (i = 0; i < 25; i++) {
        x[i] = state->x[i];
    }
    // Artificially introduce a loop-carried WAW: last element is written twice, second write depends on first
    for (i = 24; i < 25; i++) {
        x[i] = x[i] + 1;  // Depends on prior write to x[24] in previous loop
    }
}
