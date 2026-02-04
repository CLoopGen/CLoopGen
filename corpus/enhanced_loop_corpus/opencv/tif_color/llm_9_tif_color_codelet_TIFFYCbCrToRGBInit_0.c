#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with strided iteration and simplified computation
    for (i = 0; i < 256; i += 4) {
        clamptab[i]     = (TIFFRGBValue)i;
        if (i + 1 < 256) clamptab[i + 1] = (TIFFRGBValue)(i + 1);
        if (i + 2 < 256) clamptab[i + 2] = (TIFFRGBValue)(i + 2);
        if (i + 3 < 256) clamptab[i + 3] = (TIFFRGBValue)(i + 3);
    }
}
