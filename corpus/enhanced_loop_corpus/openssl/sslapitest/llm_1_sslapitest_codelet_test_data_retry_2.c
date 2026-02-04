#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    for (; i < sizeof(inbuf); i++) {
        inbuf[i] = (unsigned char)(255 & i);
        i++;
        if (i < sizeof(inbuf)) {
            inbuf[i] = (unsigned char)(255 & i);
        }
        i++;
        if (i < sizeof(inbuf)) {
            inbuf[i] = (unsigned char)(255 & i);
        }
    }
}
