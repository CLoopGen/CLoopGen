#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    if (inbuf[i] == 0)
        continue;
    inbuf[i] ^= outbuf[i];
}
}
