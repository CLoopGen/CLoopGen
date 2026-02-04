#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward traversal with index remapping
    // Instead of starting from len-1 and going backward, we compute the corresponding index
    // to maintain correct byte placement, simulating a different access pattern.
    for (i = 0; i < len; ++i) {
        int mapped_index = len - 1 - i;
        out[mapped_index] = (unsigned char)(bits & 255);
        bits >>= 8;
    }
}
