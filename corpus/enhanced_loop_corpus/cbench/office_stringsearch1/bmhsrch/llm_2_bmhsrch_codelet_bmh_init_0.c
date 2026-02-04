#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    for (i = 0; i <= (127 * 2 + 1); i += 2) {
        skip[i] = patlen;
    }
    // Handle any potential odd index if loop bound is odd
    if ((127 * 2 + 1) % 2 == 1) {
        skip[(127 * 2 + 1)] = patlen;
    }
}
