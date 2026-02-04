#include <stdio.h>

#include <inttypes.h>

extern char inbuf1[16];
extern char outbuf[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — traverse arrays from last to first element
    for (i = 15; i >= 0; --i)
        outbuf[i] ^= inbuf1[i];
}
