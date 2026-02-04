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
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = 24; i >= 0; i--)
        x[i] = state->x[i];
}
