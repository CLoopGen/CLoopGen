#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        if (outbuf[i] == 0) {
            continue;
        }
        outbuf[i] ^= inbuf1[i];
    }
}
