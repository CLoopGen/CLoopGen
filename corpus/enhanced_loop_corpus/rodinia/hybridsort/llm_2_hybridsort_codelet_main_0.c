#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sizes;
extern int newlistsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling for better spatial locality
    // Unroll by 4 to access consecutive elements and reduce loop overhead
    int limit = (1 << 10);
    for (int i = 0; i < limit; i += 4) {
        newlistsize += sizes[i] * 4;
        if (i + 1 < limit) newlistsize += sizes[i + 1] * 4;
        if (i + 2 < limit) newlistsize += sizes[i + 2] * 4;
        if (i + 3 < limit) newlistsize += sizes[i + 3] * 4;
    }
}
