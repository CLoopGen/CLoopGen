#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long i, j;
    for (i = 0; i < 16; ++i)
        for (j = 0; j < 1; ++j)
            inbuf[i] ^= outbuf[i];
}
