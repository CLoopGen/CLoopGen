#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; idx < 30; idx += 2) {
    register unsigned int v = *(const uint32_t *)&s[idx], g = v & 4278255360U;
    v &= 16711935;
    v = (v >> 16) + g + (v << 16);
    v ^= 0x12345678;
    *(uint32_t *)&d[idx] = v;
}
}
