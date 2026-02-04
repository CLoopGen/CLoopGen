#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward pass, then fill gaps in second pass)
    for (unsigned int stride = 2; stride <= 254; stride += 2)
        buf1[stride] = (stride * 2) & 255;
    for (unsigned int stride = 1; stride < 255; stride += 2)
        buf1[stride] = (stride * 2) & 255;
}
