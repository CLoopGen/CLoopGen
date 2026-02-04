#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    unsigned char temp;
    for (i = 0; i < sizeof(inbuf); i++) {
        temp = (unsigned char)(255 & (i + 1));
        inbuf[i] = temp;
    }
}
