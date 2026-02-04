#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process every 2nd element in two passes)
    // First pass: even indices
    for (Int32 j = 2; j < 257; j += 2)
        ftab[j] += ftab[j - 1];
    // Second pass: odd indices
    for (Int32 j = 1; j < 257; j += 2)
        ftab[j] += ftab[j - 1];
}
