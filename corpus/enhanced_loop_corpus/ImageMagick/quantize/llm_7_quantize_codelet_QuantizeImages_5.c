#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    size_t local_colors = colors;
    depth = 1;
    for (i = 0; local_colors != 0; i++) {
        local_colors >>= 2;
        depth = i + 1;
    }
}
