#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW and RAW dependencies
    // Each iteration depends on the previous one via a dummy accumulator
    // This creates a sequential data dependency chain (loop-carried)
    Int32 temp = 0;
    for (i = 0; i < nGroups; i++) {
        temp = pos[i] + temp;  // RAW: uses current pos[i] and previous temp
        pos[i] = temp;         // WAW: overwrites pos[i], preventing reordering
    }
}
