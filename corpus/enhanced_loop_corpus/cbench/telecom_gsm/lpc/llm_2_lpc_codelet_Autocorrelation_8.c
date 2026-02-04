#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word scalauto;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with fixed stride of 2
    for (k = 160; k--; s += 2, scalauto++)
        *s <<= scalauto;
}
