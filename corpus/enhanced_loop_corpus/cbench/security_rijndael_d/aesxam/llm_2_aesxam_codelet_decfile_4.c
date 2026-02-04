#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    for (i = 0; i < 16; i += 2) {
        if (i + 0 < 16) outbuf[i + 0] ^= bp2[i + 0];
        if (i + 1 < 16) outbuf[i + 1] ^= bp2[i + 1];
    }
}
