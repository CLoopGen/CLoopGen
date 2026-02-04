#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern JSAMPROW outptr;
extern JSAMPLE invalue;
extern int h;
extern int h_expand;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (factor of 2)
    // This modifies the memory access pattern by writing two elements per iteration when possible
    int h_unroll = h_expand / 2;
    int remainder = h_expand % 2;

    for (int i = 0; i < h_unroll; i++) {
        *outptr++ = invalue;
        *outptr++ = invalue;
    }
    
    // Handle leftover element if any
    if (remainder) {
        *outptr++ = invalue;
    }
}
