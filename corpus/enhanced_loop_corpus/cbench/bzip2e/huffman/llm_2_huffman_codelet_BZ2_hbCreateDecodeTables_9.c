#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 23; i += 2)
        limit[i] = 0;
    // Handle odd indices if needed, but since we're initializing within bounds,
    // and original loop went from 0 to 22 inclusive, ensure all are covered.
    // Continue with remaining odd indices in a second pass
    for (i = 1; i < 23; i += 2)
        limit[i] = 0;
}
