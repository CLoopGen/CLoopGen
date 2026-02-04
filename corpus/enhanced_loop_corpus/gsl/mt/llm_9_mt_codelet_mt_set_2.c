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
        unsigned long temp1 = state->mt[i - 1] ^ (state->mt[i - 1] >> 30);
        unsigned long temp2 = 1812433253UL * temp1;
        state->mt[i] = (temp2 + i) & 4294967295UL;
        
        unsigned long temp3 = state->mt[2 * i] ^ (state->mt[2 * i] >> 30);
        unsigned long temp4 = 1812433253UL * temp3;
        state->mt[2 * i + 1] = (temp4 + 2 * i + 1) & 4294967295UL;
    }
}
