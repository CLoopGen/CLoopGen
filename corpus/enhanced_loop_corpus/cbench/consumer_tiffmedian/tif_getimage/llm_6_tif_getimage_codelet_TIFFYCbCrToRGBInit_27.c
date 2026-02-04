#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a WAW (Write-After-Write) and RAW (Read-After-Write) dependency
    // by splitting the initialization into two stages with a loop-carried dependence.
    for (i = 0; i < 256; i++) {
        clamptab[i] = i + 1;  // First write: overestimates by 1
    }
    for (i = 0; i < 256; i++) {
        clamptab[i] = clamptab[i] - 1;  // Second write depends on first (RAW & WAW)
    }
}
