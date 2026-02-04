#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++)
        clamptab[i * 16 + j] = i * 16 + j;
}
