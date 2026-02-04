#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    for (i = 0; i <= 255; i += 2) {
        bigDone[i] = ((Bool)0);
        runningOrder[i] = i;
    }
    for (i = 1; i <= 255; i += 2) {
        bigDone[i] = ((Bool)0);
        runningOrder[i] = i;
    }
}
