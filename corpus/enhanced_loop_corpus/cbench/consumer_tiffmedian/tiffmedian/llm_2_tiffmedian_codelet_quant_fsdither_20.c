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
        uint32 idx = i * 3;
        nextptr[idx]     = inptr[idx];
        nextptr[idx + 1] = inptr[idx + 1];
        nextptr[idx + 2] = inptr[idx + 2];
    }
}
