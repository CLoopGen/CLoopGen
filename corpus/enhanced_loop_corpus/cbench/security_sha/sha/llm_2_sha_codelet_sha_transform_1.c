#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolling the loop to process two iterations at once
    // Access pattern: W[i], W[i-6], W[i-16], W[i-28], W[i-32] — strided and spaced out
    for (i = 16; i < 80; i += 2) {
        if (i >= 16) W[i] = W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16];
        if (i + 1 < 80) W[i + 1] = W[i - 2] ^ W[i - 7] ^ W[i - 13] ^ W[i - 15];
    }
}
