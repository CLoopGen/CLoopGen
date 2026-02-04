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
        uint32 unrolled_factor = 3;
        uint32 k;
        for (k = 0; k < unrolled_factor && (j + k) < imagewidth; ++k) {
            *nextptr++ = *inptr++;
            *nextptr++ = *inptr++;
            *nextptr++ = *inptr++;
        }
        j += k - 1;
    }
}
