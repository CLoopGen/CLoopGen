#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        inbuf[i] ^= outbuf[i];
        inbuf[15 - i] ^= outbuf[15 - i];
    }
}
