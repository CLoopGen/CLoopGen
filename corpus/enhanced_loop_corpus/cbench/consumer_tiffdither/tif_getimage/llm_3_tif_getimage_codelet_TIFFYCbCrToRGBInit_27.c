#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed order access)
    // This changes the access pattern to non-consecutive by traversing backwards
    for (i = 255; i >= 0; i--)
        clamptab[255 - i] = i;
}
