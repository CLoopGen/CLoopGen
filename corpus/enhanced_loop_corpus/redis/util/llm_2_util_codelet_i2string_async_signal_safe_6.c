#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access (reindexed to avoid negative indices)
    for (ix = 0; ix < 16; ++ix)
        buf[ix] = '0';
}
