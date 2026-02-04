#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        int double_i = i << 1;
        clamptab[double_i] = (TIFFRGBValue)double_i;
        clamptab[double_i + 1] = (TIFFRGBValue)(double_i + 1);
    }
}
