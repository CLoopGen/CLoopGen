#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified arithmetic
    // Loop runs more iterations with minimal per-element computation, increasing memory access dominance.
    Int32 start = minLen;
    Int32 end = maxLen + 5;  // Increased trip count
    for (i = start; i < end; i++) {
        base[i] = limit[i % (maxLen + 1)] + 1 - (base[i] & 1);  // Simpler expression with modulo indexing
    }
}
