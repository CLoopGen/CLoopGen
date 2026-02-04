#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
register unsigned int prev_g = 0;
for (; idx < 15; idx += 4) {
    register unsigned int v = *(const uint32_t *)&s[idx];
    register unsigned int g = (v & 16711935) ^ prev_g; // Introduce loop-carried dependency (WAW-like via prev_g)
    v &= 4278255360U;
    *(uint32_t *)&d[idx] = ((v >> 16) + g + (v << 16)) ^ prev_g; // Additional data dependency on prior iteration
    prev_g = g; // Create loop-carried dependence: current write affects next read
}
}
