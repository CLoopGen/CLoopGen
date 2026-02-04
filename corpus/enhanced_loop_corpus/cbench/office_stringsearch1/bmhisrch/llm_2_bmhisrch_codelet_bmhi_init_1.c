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
    // Variant 1: Strided memory access with step size of 2 (forward)
    int stride = 2;
    for (i = 0; i < patlen - 1; i += stride) {
        if (i < patlen - 1 && pat[i] == lastpatchar)
            skip2 = patlen - i - 1;
    }
}
