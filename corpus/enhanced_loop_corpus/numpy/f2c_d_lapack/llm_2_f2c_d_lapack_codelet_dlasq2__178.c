#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing z__ with strided index calculations, precompute indices
    // and access elements in a more sequential manner to improve cache locality.
    integer idx;
    for (k = *n << 1; k >= 2; k -= 2) {
        idx = k << 1;  // Base index for doubling
        z__[idx]     = 0.0;
        z__[idx - 1] = z__[k];
        z__[idx - 2] = 0.0;
        z__[idx - 3] = z__[k - 1];
    }
}
