#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, filling even indices first
    for (i = 0; i < 256; i += 2)
        clamptab[i] = i;
    for (i = 1; i < 256; i += 2)
        clamptab[i] = i;
}
