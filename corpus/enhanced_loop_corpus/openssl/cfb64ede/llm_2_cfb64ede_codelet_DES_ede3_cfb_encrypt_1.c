#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 8; i += 2) {
        int idx = i;
        ovec[idx] <<= num % 8;
        ovec[idx] |= ovec[idx + 1] >> (8 - num % 8);
    }
}
