#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 128; i++) {
        buf1[i] = (i * 2) & 255;
        buf1[255 - i] = (i * 4) & 255;
    }
}
