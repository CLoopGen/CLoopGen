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
    for (i = 0; i < 16; ++i) {
        int k1 = 7 + i * 6;
        int k2 = k1 + 3;
        state->ra[k1] &= mask;
        state->ra[k1] |= msb;
        state->ra[k2] &= mask >> 1;
        state->ra[k2] |= msb >> 1;
        mask >>= 2;
        msb >>= 2;
    }
}
