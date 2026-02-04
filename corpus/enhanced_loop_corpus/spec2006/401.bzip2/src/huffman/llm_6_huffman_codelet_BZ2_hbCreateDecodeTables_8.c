#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Eliminate loop-carried dependency by unrolling and reordering operations
    // This reduces the RAW (read-after-write) dependency chain by computing non-overlapping indices first.
    for (i = 1; i < 23; i += 2)
        base[i] += base[i - 1];
    
    for (i = 2; i < 23; i += 2)
        base[i] += base[i - 1];
}
