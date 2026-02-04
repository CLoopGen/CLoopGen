#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, i;
for (j = 0; j < 1; ++j)
    for (i = 0; i < 16; ++i)
        outbuf[i] ^= inbuf1[i];
}
