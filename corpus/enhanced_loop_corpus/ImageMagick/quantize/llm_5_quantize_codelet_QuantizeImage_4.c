#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 1; (colors >> (2 * (depth - 1))) > 0 && depth <= 32; depth++) {
        colors = (colors == 1) ? 0 : colors;
    }
}
