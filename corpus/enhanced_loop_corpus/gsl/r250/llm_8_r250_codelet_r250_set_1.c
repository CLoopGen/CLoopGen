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
    for (i = 0; i < 64; i += 2) {
        int k1 = 7 * i + 3;
        int k2 = 7 * (i + 1) + 3;
        state->x[k1] &= mask;
        state->x[k1] |= msb;
        mask >>= 1;
        msb >>= 1;
        if (i + 1 < 64) {
            state->x[k2] &= mask;
            state->x[k2] |= msb;
            mask >>= 1;
            msb >>= 1;
        }
    }
}
