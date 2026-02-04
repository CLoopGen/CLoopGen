#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate all loop-carried dependencies and make operations fully independent
    // Unroll the loop manually to remove index-based data flow
    #pragma unroll
    for (i = 0; i <= 63; i += 4) {
        bigDone[i]     = 0; runningOrder[i]     = i;
        bigDone[i + 1] = 0; runningOrder[i + 1] = i + 1;
        bigDone[i + 2] = 0; runningOrder[i + 2] = i + 2;
        bigDone[i + 3] = 0; runningOrder[i + 3] = i + 3;
    }
    // Handle remaining elements without creating cross-iteration dependencies
    for (; i <= 255; i++) {
        bigDone[i] = ((Bool)0);
        runningOrder[i] = (Int32)i;
    }
}
