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
    unsigned long temp;
    for (i = 1; i < 624; i++) {
        temp = state->mt[i - 1];
        state->mt[i] = (1812433253UL * (temp ^ (temp >> 30)) + i);
        state->mt[i] &= 4294967295UL;
    }
}
