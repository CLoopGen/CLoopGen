#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer = 4, inner = 4, i, j;
for (i = 0; i < outer; ++i)
    for (j = 0; j < inner; ++j)
        outbuf[i * inner + j] ^= inbuf1[i * inner + j];
}
