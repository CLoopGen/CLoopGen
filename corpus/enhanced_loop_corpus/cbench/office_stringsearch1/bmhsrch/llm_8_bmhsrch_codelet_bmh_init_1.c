#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (2x unroll) and additional arithmetic
    int i;
    int len = patlen;
    int remainder = len % 2;

    // Unroll by factor of 2 to reduce loop overhead and increase operation per iteration
    for (i = 0; i < len - remainder; i += 2) {
        skip[pat[i]]     = len - i - 1;
        skip[pat[i + 1]] = len - (i + 1) - 1;
    }

    // Handle leftover element if patlen is odd
    if (remainder == 1) {
        skip[pat[i]] = len - i - 1;
    }
}
