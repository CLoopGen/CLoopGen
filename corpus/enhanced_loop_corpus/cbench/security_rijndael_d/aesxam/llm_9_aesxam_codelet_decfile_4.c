#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        outbuf[i] ^= bp2[i];
        outbuf[15 - i] ^= bp2[15 - i];
    }
}
