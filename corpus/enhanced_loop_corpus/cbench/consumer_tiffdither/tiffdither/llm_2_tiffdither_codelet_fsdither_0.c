#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 imagewidth;
extern unsigned char *inptr;
extern short *nextptr;
extern uint32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 stride = 2;
    for (j = 0; j < imagewidth; j += stride) {
        if (j + 0 < imagewidth) *nextptr++ = inptr[j + 0];
        if (j + 1 < imagewidth) *nextptr++ = inptr[j + 1];
    }
}
