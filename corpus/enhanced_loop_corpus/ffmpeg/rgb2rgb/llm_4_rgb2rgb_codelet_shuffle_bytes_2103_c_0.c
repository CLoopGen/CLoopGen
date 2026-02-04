#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; idx < 15; idx += 4) {
    if (idx >= 0) {
        register unsigned int v = *(const uint32_t *)&s[idx], g = v & 4278255360U;
        v &= 16711935;
        *(uint32_t *)&d[idx] = (v >> 16) + g + (v << 16);
    }
}
}
