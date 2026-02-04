#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to access elements in a non-consecutive pattern
    for (i = 0; i < nGroups; i += 2) {
        pos[i] = i;
        if (i + 1 < nGroups) {
            pos[i + 1] = i + 1;
        }
    }
}
