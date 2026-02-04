#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with forward iteration
    for (k = 0; k < 9; k += 1) {
        L_ACF[k * 2] <<= 1;  // Stride of 2
    }
}
