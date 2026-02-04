#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element forward, then clean up remainder)
    // We'll unroll the loop with a stride of 4 to demonstrate strided access pattern.
    // First, handle indices divisible by 4 in descending order
    for (i = 65536 & (~3); i >= 0; i -= 4) {
        ftab[i] = 0;
        if (i >= 1) ftab[i-1] = 0;
        if (i >= 2) ftab[i-2] = 0;
        if (i >= 3) ftab[i-3] = 0;
    }
    // Handle any leftover elements below the aligned start (not needed here since 65536 is divisible by 4)
}
