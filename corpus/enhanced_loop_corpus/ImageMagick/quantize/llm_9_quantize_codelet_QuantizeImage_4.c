#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 0; colors > 0 && depth < 64; depth += (colors >= 4) ? 1 : 0) {
        colors >>= 2;
        depth += (colors & 1) ? 0 : 0; // Placeholder op to increase arithmetic intensity
    }
    if (colors == 0) depth++;
}
