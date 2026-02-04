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
    for (i = 1; i < 624; i++) {
        unsigned long temp = state->mt[i - 1];
        if (temp & 1) {
            temp ^= (temp >> 30);
        } else {
            temp ^= (temp >> 29);
        }
        state->mt[i] = (1812433253UL * temp + i);
        state->mt[i] &= 4294967295UL;
    }
}
