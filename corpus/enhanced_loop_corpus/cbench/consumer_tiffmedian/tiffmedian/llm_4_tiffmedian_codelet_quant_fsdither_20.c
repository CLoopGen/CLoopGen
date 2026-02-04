#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 imagewidth;
extern unsigned char *inptr;
extern short *nextptr;
extern uint32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < imagewidth; ++j) {
        if (j % 2 == 0) {
            *nextptr++ = *inptr++;
            *nextptr++ = *inptr++;
            *nextptr++ = *inptr++;
        } else {
            continue;
        }
    }
}
