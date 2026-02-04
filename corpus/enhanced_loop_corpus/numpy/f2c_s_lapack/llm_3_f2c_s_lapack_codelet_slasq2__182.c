#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided write access with indirect indexing via pointer arithmetic
    // Modify the original loop to use pointer arithmetic with stride-2 access on the destination
    // This increases stride in write operations while keeping the read strided as well
    // Effectively, we write only to even indices of z__, but still read from odd positions (2k-1)

    real *z_base = &z__[2];
    for (k = 2; k <= i__1; ++k) {
        if ((k & 1) == 0) {  // Only update even indices
            z_base[k - 2] = z__[(k << 1) - 1];  // Still reading from strided location
        }
    }
}
