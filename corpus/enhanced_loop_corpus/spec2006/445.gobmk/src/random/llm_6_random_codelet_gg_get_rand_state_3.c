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
    unsigned int temp[25];
    for (i = 0; i < 25; i++) {
        temp[i] = x[i];
    }
    for (i = 0; i < 25; i++) {
        state->x[i] = temp[i];
    }
}
