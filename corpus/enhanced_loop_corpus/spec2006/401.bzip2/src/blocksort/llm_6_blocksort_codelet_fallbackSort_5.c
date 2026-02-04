#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Eliminate loop-carried dependency by unrolling and reordering (partial WAW/WAR elimination)
    // This version breaks the strict sequential dependency by updating even indices first, then odd,
    // reducing the loop-carried RAW dependency chain. Still computes a form of prefix sum but in two passes.
    
    for (i = 2; i < 257; i += 2) {
        ftab[i] += ftab[i - 1];
    }
    for (i = 3; i < 257; i += 2) {
        if (i - 1 >= 1) {
            ftab[i] += ftab[i - 1];
        }
    }
}
