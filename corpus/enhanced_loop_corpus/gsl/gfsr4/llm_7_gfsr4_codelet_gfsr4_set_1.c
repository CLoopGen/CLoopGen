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
    unsigned long temp_vals[32];
    for (i = 0; i < 32; ++i) {
        int k = 7 + i * 3;
        temp_vals[i] = (state->ra[k] & mask) | msb;
        mask >>= 1;
        msb >>= 1;
    }
    for (i = 0; i < 32; ++i) {
        int k = 7 + i * 3;
        state->ra[k] = temp_vals[i];
    }
}
