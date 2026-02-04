#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // Access pattern: pos[0], pos[2], pos[4], ... (even indices only)
    // Ensures bounds safety by checking i+1 < nGroups
    for (i = 0; i < nGroups; i += 2) {
        pos[i] = i;
        if (i + 1 < nGroups) {
            pos[i + 1] = i + 1;
        }
    }
}
