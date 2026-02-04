#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely
    // Unroll simulation with independent operations
    // No data dependency between iterations (fully parallelizable)
    Int32 j = 0;
    for (i = 0; j < nGroups; i++, j++) {
        pos[j] = i;  // Write to distinct pos elements, no reuse of written values in subsequent iterations
    }
}
