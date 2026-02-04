#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely and unroll partially
    // This version removes all loop-carried data dependencies by making each iteration independent.
    // Also introduces parallelism potential via elimination of RAW, WAR, WAW across iterations.
    #pragma unroll
    for (i = 0; i < nGroups && i < 6; i++) {
        // Each iteration computes independently with no inter-iteration data flow
        // Using local computation to break dependencies
        UChar value = (UChar)(i & 0xFF); // Local derivation, no dependency on prior iterations
        pos[i] = value;
    }
}
