#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 k;
    for (k = 255; k >= 0; k--) {
        ftabCopy[k] = ftab[k]; // Reverse loop direction to eliminate potential loop-carried dependence in forward direction
        // No dependency on previous iteration; independent accesses
    }
}
