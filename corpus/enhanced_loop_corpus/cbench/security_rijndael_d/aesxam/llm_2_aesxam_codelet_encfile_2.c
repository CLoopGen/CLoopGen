#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 16; i += 2) {
        if (i + 1 < 16) {
            inbuf[i] ^= outbuf[i];
            inbuf[i + 1] ^= outbuf[i + 1];
        } else {
            inbuf[i] ^= outbuf[i];
        }
    }
}
