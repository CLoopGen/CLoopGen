#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolled to maintain logic
    for (i = 0; i < 8; i += 2) {
        if (i + 2 < 16) {
            ovec[i] <<= num % 8;
            ovec[i] |= ovec[i + 2] >> (8 - num % 8);
        }
        if (i + 1 < 8) {
            ovec[i + 1] <<= num % 8;
            ovec[i + 1] |= ovec[i + 3] >> (8 - num % 8);
        }
    }
}
