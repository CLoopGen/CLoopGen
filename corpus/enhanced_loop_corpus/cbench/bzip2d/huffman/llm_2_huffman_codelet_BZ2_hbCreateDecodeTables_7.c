#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *base;
extern UChar *length;
extern Int32 alphaSize;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing length[0], length[1], ..., we access every 2nd element forward and backward
    // To maintain correctness, we simulate the original effect using a stride of 1 but with reversed order
    // This preserves functionality while altering access pattern to descending consecutive
    for (i = alphaSize - 1; i >= 0; i--)
        base[length[i] + 1]++;
}
