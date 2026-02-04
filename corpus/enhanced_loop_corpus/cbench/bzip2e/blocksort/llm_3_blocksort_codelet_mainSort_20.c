#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index permutation (reverse order)
    Int32 indices[256];
    for (i = 0; i <= 255; i++) {
        indices[i] = 255 - i; // reverse mapping
    }
    for (i = 0; i <= 255; i++) {
        Int32 idx = indices[i];
        bigDone[idx] = ((Bool)0);
        runningOrder[idx] = idx;
    }
}
