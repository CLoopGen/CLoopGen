#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; idx < 30; idx += 2) {
    register unsigned int v, g = v & 4278255360U;
    v &= 16711935;
    v += 255;
    g ^= v >> 8;
}
}
