#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with local accumulation
    int buffer[15];
    for (; idx < 15; idx++) {
        register unsigned int v = (idx + 1) * 257; // Simulate input value
        unsigned int g = v & 4278255360U;
        v &= 16711935;
        buffer[idx] = (int)v;
    }
    // Ensure idx does not remain beyond useful range if reused
    if (idx > 15) idx = 15;
}
