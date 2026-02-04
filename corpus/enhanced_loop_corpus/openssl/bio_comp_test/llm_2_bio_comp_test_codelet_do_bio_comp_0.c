#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (i = 0; i < 32 * 1024; i += 4) {
        original[i] = i & 255;
        if (i + 1 < 32 * 1024) original[i + 1] = (i + 1) & 255;
        if (i + 2 < 32 * 1024) original[i + 2] = (i + 2) & 255;
        if (i + 3 < 32 * 1024) original[i + 3] = (i + 3) & 255;
    }
}
