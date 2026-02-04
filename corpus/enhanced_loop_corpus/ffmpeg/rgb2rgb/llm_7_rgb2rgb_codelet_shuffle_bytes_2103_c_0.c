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
    register unsigned int g = (v & 4278255360U) ^ prev_g; // Introduce loop-carried dependency (WAW/RAR via `prev_g`)
    v &= 16711935;
    *(uint32_t *)&d[idx] = (v >> 16) + g + (v << 16);
    prev_g = g >> 8; // Feedback dependency to next iteration
}
}
