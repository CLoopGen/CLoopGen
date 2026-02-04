#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling by 3
    int upper = i + (6 + 3);
    for (; i < upper; i += 3) {
        *xi++ = 0;
        *xi++ = 0;
        *xi++ = 0;
    }
}
