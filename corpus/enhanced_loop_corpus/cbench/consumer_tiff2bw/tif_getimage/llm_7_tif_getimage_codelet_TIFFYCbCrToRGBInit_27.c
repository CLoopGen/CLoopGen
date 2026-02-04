#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    TIFFRGBValue acc = 0;
    for (i = 0; i < 256; i++) {
        acc += i;
        clamptab[i] = acc;
    }
}
