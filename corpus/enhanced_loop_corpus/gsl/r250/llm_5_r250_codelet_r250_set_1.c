#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

extern r250_state_t *state;
extern int i;
extern unsigned long msb;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; ++i) {
    int k = 7 * i + 3;
    state->x[k] &= mask;
    if (msb > 0x80000000UL) {
        state->x[k] |= msb;
    }
    mask >>= 1;
    msb >>= 1;
}
}
