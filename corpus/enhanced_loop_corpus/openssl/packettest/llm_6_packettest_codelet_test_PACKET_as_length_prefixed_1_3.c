#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[255];
    for (i = 1; i < 255; i++) {
        temp[i] = (i * 2) & 255;
        buf1[i] = temp[i];
    }
}
