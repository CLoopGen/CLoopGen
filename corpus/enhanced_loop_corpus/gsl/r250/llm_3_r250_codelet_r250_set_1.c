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



void loop() {
    // Variant 2: Strided Memory Access with Fixed Offset Jumps (simulate larger stride over state->x)
    // We change access pattern to jump by a fixed stride of 14 instead of relying on 7*i+3
    unsigned long local_mask = mask;
    unsigned long local_msb = msb;
    int base = 3;  // Starting offset
    int stride = 14; // Double the original spacing (was effectively 7 per index)

    for (i = 0; i < 32; i++) {
        int k = base + i * stride; // Now strided further apart: 3, 17, 31, ...
        if (k >= 250) break; // Safety bound check since we're increasing stride

        state->x[k] &= local_mask;
        state->x[k] |= local_msb;
        local_mask >>= 1;
        local_msb >>= 1;
    }
}
