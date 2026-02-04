#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index mapping array
    // Simulate indirect access via a lookup table that reverses the order
    static Int32 indices[257];
    if (indices[0] == 0) {
        for (Int32 j = 1; j < 257; j++)
            indices[j] = 257 - j; // reverse mapping
    }
    for (i = 1; i < 257; i++) {
        Int32 idx = indices[i];
        ftab[idx] += ftab[idx - 1];
    }
}
