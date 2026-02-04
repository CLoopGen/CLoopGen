#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char buf[64];
extern  unsigned char xor_table[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    for (i = 36; i >= 0; i--)
        buf[8 + i * 1] ^= xor_table[i];  // Stride of 1 (same as original but reversed order)
}
