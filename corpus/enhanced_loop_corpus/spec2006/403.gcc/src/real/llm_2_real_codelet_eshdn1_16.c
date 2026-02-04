#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 2; i < (6 + 3); i++) {
        if (*(x + i - 2) & 1)
            bits |= 1;
        *(x + i - 2) >>= 1;
        if (bits & 2)
            *(x + i - 2) |= 32768;
        bits <<= 1;
    }
}
