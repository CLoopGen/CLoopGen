#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max_depth = 0;
    for (; i > 1; ) {
        i >>= 1;
        max_depth++;
    }
    if (i == 1) max_depth++;
}
