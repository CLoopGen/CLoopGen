#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Precompute indices in reverse order to create a non-sequential access pattern
    Int32 indices[257];
    for (i = 0; i < 257; i++) {
        indices[i] = 256 - i; // Reverse mapping: access from last to first
    }
    for (i = 0; i < 257; i++) {
        ftab[indices[i]] = 0;
    }
}
