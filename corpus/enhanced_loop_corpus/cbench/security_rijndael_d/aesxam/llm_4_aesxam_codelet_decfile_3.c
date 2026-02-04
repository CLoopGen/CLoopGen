#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        if (inbuf1[i] != 0) {
            outbuf[i] ^= inbuf1[i];
        }
    }
}
