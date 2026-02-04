#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        unsigned int idx = i << 1;
        unsigned char val1 = ((idx + 1) * 2) & 255;
        unsigned char val2 = ((idx + 2) * 2) & 255;
        buf[idx] = val1;
        buf[idx + 1] = val2;
    }
}
