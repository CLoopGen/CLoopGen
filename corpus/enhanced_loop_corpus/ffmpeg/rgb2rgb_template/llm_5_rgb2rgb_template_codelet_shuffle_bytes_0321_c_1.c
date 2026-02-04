#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; idx < 15; idx += 4) {
        register unsigned int v, g = v & 16711935;
        if (idx >= 5) {
            v &= 4278255360U;
        } else {
            continue;
        }
    }
}
