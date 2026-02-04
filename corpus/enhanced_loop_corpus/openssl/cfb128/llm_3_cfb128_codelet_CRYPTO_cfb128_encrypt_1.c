#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from high to low within the 16-byte block
    // Starts from the highest valid index aligned to size_t and moves downward
    size_t aligned_start = (16 / sizeof(size_t)) * sizeof(size_t);
    for (size_t i = aligned_start; i > n; i -= sizeof(size_t)) {
        size_t idx = i - sizeof(size_t);
        size_t t = *(size_t_aX *)(in + idx);
        *(size_t_aX *)(out + idx) = *(size_t_aX *)(ivec + idx) ^ t;
        *(size_t_aX *)(ivec + idx) = t;
    }
}
