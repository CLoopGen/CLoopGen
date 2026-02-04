#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

extern unsigned long s;
extern mt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 312; i++) {
        unsigned long temp1 = s;
        s = ((69069 * s) + 1) & 4294967295UL;
        unsigned long temp2 = s;
        s = ((69069 * s) + 1) & 4294967295UL;

        state->mt[2*i] = temp1 & 4294901760UL;
        state->mt[2*i] |= (temp2 & 4294901760UL) >> 16;

        s = ((69069 * s) + 1) & 4294967295UL;
        unsigned long temp3 = s;
        s = ((69069 * s) + 1) & 4294967295UL;
        unsigned long temp4 = s;
        s = ((69069 * s) + 1) & 4294967295UL;

        state->mt[2*i+1] = temp3 & 4294901760UL;
        state->mt[2*i+1] |= (temp4 & 4294901760UL) >> 16;
    }
}
