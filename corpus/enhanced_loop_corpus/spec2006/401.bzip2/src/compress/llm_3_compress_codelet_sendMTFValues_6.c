#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Here, we reverse the order of assignment: write from end to start using indirect-like indexing
    for (i = 0; i < nGroups; i++) {
        Int32 idx = (nGroups - 1) - i;  // Indirect addressing: reverse mapping
        pos[idx] = idx;
    }
}
