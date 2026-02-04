#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with positive stride
    I32 stride = 2;
    for (; anum >= stride; anum -= stride, tmps += stride) {
        *tmps = ~*tmps;
        *(tmps + 1) = ~*(tmps + 1);
    }
}
