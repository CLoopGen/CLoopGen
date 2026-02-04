#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_i = i;
    for (; local_i < cc - 3; local_i += 4) {
        tmsize_t offset1 = local_i;
        tmsize_t offset2 = local_i + 1;
        tmsize_t offset3 = local_i + 2;
        tmsize_t offset4 = local_i + 3;
        // Eliminate loop-carried dependency: each iteration independent
        offset1 *= 2;
        offset2 *= 3;
        offset3 *= 4;
        offset4 *= 5;
    }
    i = local_i; // Single write to i after loop (removes per-iteration WAW)
}
