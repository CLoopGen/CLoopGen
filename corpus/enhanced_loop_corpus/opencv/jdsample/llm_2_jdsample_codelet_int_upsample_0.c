#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern JSAMPROW outptr;
extern JSAMPLE invalue;
extern int h;
extern int h_expand;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling (stride of 2)
    // Unroll the loop by accessing two consecutive elements per iteration when possible
    int h_step = h_expand / 2;
    JSAMPROW ptr = outptr;
    
    for (int i = h_step; i > 0; i--) {
        *ptr++ = invalue;
        *ptr++ = invalue;
    }
    // Handle remaining element if h_expand is odd
    if (h_expand % 2 == 1) {
        *ptr++ = invalue;
    }
    outptr = ptr; // Update original pointer
}
