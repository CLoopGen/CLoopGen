#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 16; i += 2) {
        if (i + 0 < 16) outbuf[i + 0] ^= inbuf1[i + 0];
        if (i + 1 < 16) outbuf[i + 1] ^= inbuf1[i + 1];
    }
}
