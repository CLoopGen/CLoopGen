#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long i;
    for (i = 0; i < 4; ++i) {
        inbuf[i*4 + 0] ^= outbuf[i*4 + 0];
        inbuf[i*4 + 1] ^= outbuf[i*4 + 1];
        inbuf[i*4 + 2] ^= outbuf[i*4 + 2];
        inbuf[i*4 + 3] ^= outbuf[i*4 + 3];
    }
}
