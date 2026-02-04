#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    int limit = i + (6 - 2);
    for (; i < limit; i++) {
        *x++ = 0;
        *x++ = 0;  // Unroll by writing two elements consecutively
    }
    // Adjust final state: we may have written one extra if count is odd
    x--; // Compensate for over-increment due to unrolling
}
