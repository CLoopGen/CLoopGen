#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i += 2) {
        clamptab[i % 256] = i % 256;
        clamptab[(i + 1) % 256] = (i + 1) % 256;
    }
}
