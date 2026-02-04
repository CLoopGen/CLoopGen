#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // and a RAW (Read-After-Write) dependency by making each write depend on the previous iteration.
    // This creates a sequential dependency across iterations.
    pos[0] = 0;
    for (i = 1; i < nGroups; i++) {
        pos[i] = pos[i - 1] + 1;  // Each write depends on prior written value
    }
}
