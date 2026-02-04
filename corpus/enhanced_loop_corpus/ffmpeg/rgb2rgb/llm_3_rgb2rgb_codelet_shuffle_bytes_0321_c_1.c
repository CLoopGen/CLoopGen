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
    const int offset = (idx * 3) % 16;
    register unsigned int v = *(const uint32_t *)&s[offset], g = v & 16711935;
    v &= 4278255360U;
    *(uint32_t *)&d[offset] = (v >> 16) + g + (v << 16);
}
}
