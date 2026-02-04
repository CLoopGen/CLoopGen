#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    buf1[1] = 2;
    for (i = 2; i < 255; i++)
        buf1[i] = (buf1[i-1] + 2) & 255;
}
