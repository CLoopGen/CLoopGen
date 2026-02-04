#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and rewritten for forward sequential access)
    register int i;
    for (i = idx; i < 15; i += 4) {
        register unsigned int v = *(const uint32_t *)&s[i];
        register unsigned int g = v & 4278255360U;
        v &= 16711935;
        *(uint32_t *)&d[i] = (v >> 16) + g + (v << 16);
    }
    idx = i; // Update idx to reflect progress
}
