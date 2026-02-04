#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 imagewidth;
extern unsigned char *inptr;
extern short *nextptr;
extern uint32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 i;
    for (i = 0; i < imagewidth; ++i) {
        short temp1 = *inptr++;
        short temp2 = *inptr++;
        short temp3 = *inptr++;
        *nextptr++ = temp1;
        *nextptr++ = temp2;
        *nextptr++ = temp3;
    }
}
