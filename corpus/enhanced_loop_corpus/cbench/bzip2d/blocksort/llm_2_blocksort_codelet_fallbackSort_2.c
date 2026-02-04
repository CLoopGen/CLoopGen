#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), unrolling the loop to write every other element
    // Fill even indices first, then odd indices in a second pass to maintain correctness
    for (Int32 stride = 0; stride < 2; stride++) {
        for (i = stride; i < 257; i += 2) {
            ftab[i] = 0;
        }
    }
}
