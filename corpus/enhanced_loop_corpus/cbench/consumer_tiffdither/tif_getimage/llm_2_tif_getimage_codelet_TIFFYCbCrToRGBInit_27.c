#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even indices
    for (i = 0; i < 256; i += 2) {
        clamptab[i] = i;
        if (i + 1 < 256)
            clamptab[i + 1] = i + 1;
    }
}
