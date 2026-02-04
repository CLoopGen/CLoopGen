#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = 0;
    for (i = 0; i < 16; ++i) {
        char current = inbuf[i] ^ outbuf[i] ^ prev;
        inbuf[i] = current;
        prev = current;
    }
}
