#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        outbuf[2*i] ^= inbuf1[2*i];
        outbuf[2*i+1] ^= inbuf1[2*i+1];
    }
}
