#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 imagewidth;
extern unsigned char *inptr;
extern short *nextptr;
extern uint32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 k;
    for (k = 0; k < (imagewidth + 3) / 4; ++k) {
        *nextptr++ = (*inptr++) * 2 + 1;
        *nextptr++ = (*inptr++) * 2 + 1;
        *nextptr++ = (*inptr++) * 2 + 1;
        *nextptr++ = (*inptr++) * 2 + 1;
    }
}
