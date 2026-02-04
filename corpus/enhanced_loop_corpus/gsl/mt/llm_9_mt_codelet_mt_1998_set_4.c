#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

extern mt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 312; i++) {
        unsigned long val = state->mt[i - 1];
        state->mt[2*i]     = ((69069 * val) & 4294967295UL);
        state->mt[2*i - 1] = ((1812433253 * val + i) & 4294967295UL);
    }
}
