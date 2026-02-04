#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    // Access pos in reverse order to create non-consecutive access pattern
    for (i = 0; i < nGroups; i++) {
        Int32 idx = nGroups - 1 - i;  // Reverse indexing
        pos[idx] = idx;
    }
}
