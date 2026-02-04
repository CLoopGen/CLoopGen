#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        if (bp2[i] == 0) {
            continue;
        }
        outbuf[i] ^= bp2[i];
    }
}
