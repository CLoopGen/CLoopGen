#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        if (i % 2 == 0)
            clamptab[i] = (TIFFRGBValue)i;
        else
            clamptab[i] = (TIFFRGBValue)(i - 1);
    }
}
