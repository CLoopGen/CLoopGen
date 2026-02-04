#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (k, k+64, ...), we reorganize to use consecutive indices.
    // We assume the data has been pre-reorganized into a different layout where
    // groups of 5 elements are stored consecutively. For realism, we simulate this
    // by accessing blocks in a coalesced pattern starting from base = k * 5.
    for (k = 0; k < 64; k++) {
        INTFLOAT base = k * 5;
        INTFLOAT f = z[base] + z[base + 1] + z[base + 2] + z[base + 3] + z[base + 4];
        z[k] = f;
    }
}
