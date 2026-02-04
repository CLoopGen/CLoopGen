#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t local_n = n;
    size_t local_depth = 1;
    for (; local_n != 0; local_n >>= 2, local_depth++)
        depth = local_depth; // WAW dependency introduced: write-after-write on 'depth'
    depth = local_depth; // Final update to ensure correctness
}
