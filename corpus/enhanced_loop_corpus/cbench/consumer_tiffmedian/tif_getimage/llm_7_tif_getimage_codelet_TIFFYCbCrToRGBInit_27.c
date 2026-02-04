#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate apparent loop-carried dependencies and unroll to increase parallelism
    // This version uses independent writes with no inter-element dependencies, enabling vectorization.
    for (i = 0; i < 256; i += 4) {
        clamptab[i]     = i;
        if (i + 1 < 256) clamptab[i + 1] = i + 1;
        if (i + 2 < 256) clamptab[i + 2] = i + 2;
        if (i + 3 < 256) clamptab[i + 3] = i + 3;
    }
}
