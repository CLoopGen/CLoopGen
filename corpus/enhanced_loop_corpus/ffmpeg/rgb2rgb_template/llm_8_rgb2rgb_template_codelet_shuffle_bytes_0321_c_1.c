#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; idx < 60; idx += 3) {
        register unsigned int v, g = v & 16711935;
        g ^= v >> 8;
        v &= 4278255360U;
        v += g * 2;
    }
}
