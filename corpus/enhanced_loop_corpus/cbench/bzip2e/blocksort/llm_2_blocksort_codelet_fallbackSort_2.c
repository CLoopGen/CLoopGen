#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), unrolling the loop to write every second element in two passes
    Int32 limit = 257;
    
    // First pass: set even indices
    for (i = 0; i < limit; i += 2)
        ftab[i] = 0;

    // Second pass: set odd indices
    for (i = 1; i < limit; i += 2)
        ftab[i] = 0;
}
