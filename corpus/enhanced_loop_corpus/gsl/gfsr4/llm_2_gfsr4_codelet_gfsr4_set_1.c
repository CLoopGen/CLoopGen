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
for (i = 0; i < 32; ++i) {
    int k = 7 + i * 3;
    // Change to consecutive memory access by reordering computation and using temporary storage
    unsigned long temp = state->ra[k];
    temp &= mask;
    temp |= msb;
    state->ra[k] = temp;
    mask >>= 1;
    msb >>= 1;
}
}
