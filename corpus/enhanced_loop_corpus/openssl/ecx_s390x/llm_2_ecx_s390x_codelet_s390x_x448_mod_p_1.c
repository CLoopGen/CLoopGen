#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, descending)
    for (i = 54; i >= 28; i -= 2) {
        c += (unsigned int)u_red[i];
        u_red[i] = (unsigned char)c;
        c >>= 8;
    }
}
