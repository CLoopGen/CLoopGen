#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency
    // by writing to the same location multiple times in a dependent manner.
    // Here, we ensure each write depends on the previous iteration's write,
    // creating a loop-carried dependence that prevents parallelization.

    clamptab[0] = 0;
    for (i = 1; i < 256; i++) {
        clamptab[i] = clamptab[i - 1] + 1;  // WAW and flow dependence on previous write
    }
}
