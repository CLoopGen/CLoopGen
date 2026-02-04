#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 imagewidth;
extern unsigned char *inptr;
extern short *nextptr;
extern uint32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 offset;
    for (offset = 0; offset < imagewidth; ++offset) {
        uint32 idx = offset * 3;
        *(nextptr + idx)     = *(inptr + idx);
        *(nextptr + idx + 1) = *(inptr + idx);
        *(nextptr + idx + 2) = *(inptr + idx);
    }
}
