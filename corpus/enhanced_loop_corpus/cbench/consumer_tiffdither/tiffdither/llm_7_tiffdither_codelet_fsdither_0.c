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
        nextptr[i] = (short)inptr[i];
    }
}
