#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 * sizeof(size_t)
    // Processes every second size_t-aligned chunk, forward traversal
    size_t stride = 2 * sizeof(size_t);
    for (; n + stride <= 16; n += stride) {
        size_t t = *(size_t_aX *)(in + n);
        *(size_t_aX *)(out + n) = *(size_t_aX *)(ivec + n) ^ t;
        *(size_t_aX *)(ivec + n) = t;
    }
    // Handle remaining elements with original step if needed
    for (; n < 16; n += sizeof(size_t)) {
        size_t t = *(size_t_aX *)(in + n);
        *(size_t_aX *)(out + n) = *(size_t_aX *)(ivec + n) ^ t;
        *(size_t_aX *)(ivec + n) = t;
    }
}
