#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;
extern int lastpatchar;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (unrolled-like pattern)
    // We traverse the array in strides, checking every second element first, then offset
    int stride = 2;
    int remainder = (patlen - 1) % stride;

    // First pass: process indices with stride
    for (i = 0; i < patlen - 1; i += stride) {
        if (pat[i] == lastpatchar)
            skip2 = patlen - i - 1;
    }
    // Second pass: handle the offset if needed (remainder case)
    for (i = 1; i < patlen - 1 && stride > 1; i += stride) {
        if (pat[i] == lastpatchar)
            skip2 = patlen - i - 1;
    }
}
