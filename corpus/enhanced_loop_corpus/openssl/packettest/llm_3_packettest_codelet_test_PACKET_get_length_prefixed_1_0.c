#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from high to low index)
    for (i = 254; i >= 1; i--)
        buf1[i] = (i * 2) & 255;
}
