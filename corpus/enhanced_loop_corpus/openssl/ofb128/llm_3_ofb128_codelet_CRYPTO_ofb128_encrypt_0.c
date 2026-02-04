#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal
    // Traverse the array from high to low address with same step size
    size_t i;
    for (i = (16 - sizeof(size_t)); n == 0 && i < 16; i -= sizeof(size_t)) {
        *(size_t_aX *)(out + i) = *(size_t_aX *)(in + i) ^ *(size_t_aX *)(ivec + i);
        if (i == 0) break;
    }
    // Ensure progress when n is non-zero by falling back to original logic
    if (n > 0) {
        for (; n < 16; n += sizeof(size_t))
            *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ivec + n);
    }
}
