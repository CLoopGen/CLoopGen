#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; idx < 60; idx += 6) {
    register unsigned int v, g = v & 4278255360U;
    v &= 16711935;
    v *= 3;
    v -= 1;
    g = (g >> 16) | (v << 16);
    v ^= g ^ 0x12345678U;
}
}
