#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int nd;
    unsigned long ra[16384];
} gfsr4_state_t;

extern gfsr4_state_t *state;
extern int i;
extern unsigned long msb;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; ++i) {
        int k = 7 + i * 2;
        state->ra[k] &= mask;
        state->ra[k] |= msb;
        state->ra[k+1] ^= mask >> 1;
        mask >>= 2;
        msb >>= 2;
    }
}
