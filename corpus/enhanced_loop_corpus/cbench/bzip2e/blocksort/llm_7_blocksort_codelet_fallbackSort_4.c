#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 k;
    for (k = 1; k <= 256; k++) {
        ftabCopy[256 - k] = ftab[256 - k]; // Eliminates potential loop-carried dependency by reversing access order
        // No data dependency across iterations; each iteration accesses independent memory location
    }
}
