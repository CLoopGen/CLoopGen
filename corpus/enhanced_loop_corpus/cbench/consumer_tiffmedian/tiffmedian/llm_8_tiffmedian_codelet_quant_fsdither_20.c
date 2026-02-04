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
    for (j = 0; j < imagewidth * 3; ++j) {
        *nextptr++ = *inptr++;
    }
}
