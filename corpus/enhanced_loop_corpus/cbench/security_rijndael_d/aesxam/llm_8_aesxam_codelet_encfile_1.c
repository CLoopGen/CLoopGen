#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        inbuf[i] ^= outbuf[i];
        if (i + 1 < 16)
            inbuf[i + 1] ^= outbuf[i + 1];
    }
}
