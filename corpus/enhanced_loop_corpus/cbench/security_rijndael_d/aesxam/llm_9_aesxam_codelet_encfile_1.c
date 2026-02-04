#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; ++i) {
        size_t idx = i % 16;
        inbuf[idx] ^= outbuf[idx];
        inbuf[idx] += 1;
        outbuf[idx] -= 1;
    }
}
