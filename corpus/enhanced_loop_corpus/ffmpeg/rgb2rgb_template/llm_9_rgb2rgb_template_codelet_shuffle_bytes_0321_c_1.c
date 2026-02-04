#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; idx < 8; idx += 8) {
        register unsigned int v, g = v & 16711935;
        v &= 4278255360U;
        if (v > 1000) {
            g += v >> 16;
            g &= 65535;
        }
    }
}
