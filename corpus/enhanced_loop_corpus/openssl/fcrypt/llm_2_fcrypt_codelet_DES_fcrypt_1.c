#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolled to maintain functionality
    // Accesses even indices first, then odd indices in a second pass to cover all 8 elements
    for (i = 0; i < 8; i += 2)
        key[i] = 0;
    for (i = 1; i < 8; i += 2)
        key[i] = 0;
}
