#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1; j < 16; ++j) {
        outbuf[j] ^= bp2[j];
        outbuf[j] ^= outbuf[j-1]; // Introduces WAW and RAW loop-carried dependency
    }
    if (16 > 0)
        outbuf[0] ^= bp2[0];
}
