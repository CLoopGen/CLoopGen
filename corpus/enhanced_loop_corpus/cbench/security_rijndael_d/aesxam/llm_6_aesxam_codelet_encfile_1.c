#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp[16];
    for (i = 0; i < 16; ++i)
        temp[i] = inbuf[i] ^ outbuf[i];
    for (i = 0; i < 16; ++i)
        inbuf[i] = temp[i];
}
