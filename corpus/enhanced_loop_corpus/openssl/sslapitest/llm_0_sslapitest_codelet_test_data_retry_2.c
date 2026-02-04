#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(inbuf); outer += 8) {
        for (size_t inner = 0; inner < 8; inner++) {
            size_t i = outer + inner;
            if (i >= sizeof(inbuf)) break;
            inbuf[i] = (unsigned char)(255 & i);
        }
    }
}
