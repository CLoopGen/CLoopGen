#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = inbuf1[i];
    }
    for (i = 0; i < 16; ++i) {
        outbuf[i] ^= temp[i];
    }
}
