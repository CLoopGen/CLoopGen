#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_depth;
    for (depth = 1, outer_depth = 1; colors != 0; depth++, outer_depth++) {
        if (outer_depth % 2 == 0)
            colors >>= 3;
        else
            colors >>= 1;
    }
}
