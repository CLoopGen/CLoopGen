#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 512; i++) {
        unsigned int x = i * 4;
        x = (x + (x >> 2)) & 255;
        buf1[i*2 - 2] = x;
        buf1[i*2 - 1] = (x ^ 128) & 255;
    }
}
