#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(inbuf) / 2; i++) {
        size_t j = 2 * i;
        inbuf[j] = (unsigned char)(255 & (j ^ (j >> 1)));
        inbuf[j + 1] = (unsigned char)(255 & ((j + 1) ^ ((j + 1) >> 1)));
    }
}
