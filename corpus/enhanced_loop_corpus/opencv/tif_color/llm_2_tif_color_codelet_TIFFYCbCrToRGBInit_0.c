#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), with forward and backward fill
    for (i = 0; i < 256; i += 2) {
        clamptab[i] = (TIFFRGBValue)i;
        if (i + 1 < 256)
            clamptab[i + 1] = (TIFFRGBValue)(i + 1);
    }
}
