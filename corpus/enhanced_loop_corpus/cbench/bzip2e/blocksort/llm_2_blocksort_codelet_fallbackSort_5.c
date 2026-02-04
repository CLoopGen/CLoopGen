#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process every 2nd element in two passes)
    // First pass: even indices
    for (i = 2; i < 257; i += 2)
        ftab[i] += ftab[i - 1];
    // Second pass: odd indices
    for (i = 1; i < 257; i += 2)
        ftab[i] += ftab[i - 1];
}
