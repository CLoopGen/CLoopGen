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
    register unsigned int v = *(const uint32_t *)&s[idx];
    register unsigned int g = v & 16711935;
    register unsigned int b = (v & 4278255360U) >> 16;
    register unsigned int r = (v & 4278255360U) << 16;
    register unsigned int result = r + g + b;
    *(uint32_t *)&d[idx] = result ^ ((result << 8) | (result >> 24));
}
}
