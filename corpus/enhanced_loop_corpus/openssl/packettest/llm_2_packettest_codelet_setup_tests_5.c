#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive write access with reversed iteration order (backward traversal)
    for (i = 255; i >= 1; i--)
        smbuf[i - 1] = (i * 2) & 255;
}
