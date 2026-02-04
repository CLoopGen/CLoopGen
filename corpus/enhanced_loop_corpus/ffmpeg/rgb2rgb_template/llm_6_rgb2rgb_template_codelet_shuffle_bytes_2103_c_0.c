#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    register unsigned int v = 0, g;
    for (; idx < 15; idx += 4) {
        v ^= (unsigned int)idx * 31;  // Introduce loop-carried dependency: v depends on previous iteration via XOR
        g = v & 4278255360U;
        v &= 16711935;
    }
}
