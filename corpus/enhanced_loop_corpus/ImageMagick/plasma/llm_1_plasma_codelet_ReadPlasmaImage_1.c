#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max_depth = 0; i != 0 && (i & 1) == 0; max_depth++) {
        i >>= 1;
    }
    if (i != 0) {
        max_depth++;
    }
}
