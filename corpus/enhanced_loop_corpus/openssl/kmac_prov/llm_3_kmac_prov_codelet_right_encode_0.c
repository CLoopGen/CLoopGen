#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with zero-padding for alignment
    // Assume len is multiple of stride for simplicity. Here, use stride of 2 for alternating access.
    // We write every other byte first (even indices), then fill in odd indices in a second pass.
    // This splits the original loop into two consecutive loops with strided access.

    // First pass: write to even indices in reverse order
    for (i = len - 1; i >= 0; i -= 2) {
        out[i] = (unsigned char)(bits & 255);
        bits >>= 8;
    }

    // Second pass: write to odd indices in reverse order
    for (i = len - 2; i >= 0; i -= 2) {
        out[i] = (unsigned char)(bits & 255);
        bits >>= 8;
    }
}
