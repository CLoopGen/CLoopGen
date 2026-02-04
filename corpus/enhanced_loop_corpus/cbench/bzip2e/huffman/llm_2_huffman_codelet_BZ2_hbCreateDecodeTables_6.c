#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 23; i += 2)
        base[i] = 0;
    // Handle odd indices if needed, but since original loop covers all from 0 to 22,
    // we complete the remaining index accesses with a second pass
    for (i = 1; i < 23; i += 2)
        base[i] = 0;
}
