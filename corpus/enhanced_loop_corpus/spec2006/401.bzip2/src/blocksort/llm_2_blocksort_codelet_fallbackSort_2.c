#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling the loop to handle even and odd indices
    // Initialize even indices first, then odd indices in a separate pass
    for (Int32 stride = 0; stride < 2; stride++) {
        for (i = stride; i < 257; i += 2) {
            ftab[i] = 0;
        }
    }
}
