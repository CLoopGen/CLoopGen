#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t size = sizeof(inbuf);
    for (size_t i = 0; i < size; i += 2) {
        inbuf[i] = (unsigned char)(255 & i);
        if (i + 1 < size)
            inbuf[i + 1] = (unsigned char)(255 & (i + 1));
    }
}
