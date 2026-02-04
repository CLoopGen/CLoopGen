#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 0; colors > 1; depth += 3) {
        colors >>= 1;
        if (colors > 1) colors >>= 1;
        if (colors > 1) colors >>= 1;
    }
    depth++;
}
