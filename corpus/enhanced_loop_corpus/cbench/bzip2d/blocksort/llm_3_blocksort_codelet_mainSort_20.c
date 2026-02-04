#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a lookup table for shuffled indices
    Int32 shuffleMap[256];
    for (i = 0; i <= 255; i++) {
        shuffleMap[i] = (i * 17) % 256; // Simple deterministic permutation
    }
    for (i = 0; i <= 255; i++) {
        Int32 j = shuffleMap[i]; // Indirect access via shuffled index
        bigDone[j] = ((Bool)0);
        runningOrder[j] = j;
    }
}
