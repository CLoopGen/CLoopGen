#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = sizeof(size_t);
    for (; n < 16; n += step) {
        size_t aligned_n = n & ~(sizeof(size_t) - 1);
        if (aligned_n + sizeof(size_t) <= 16)
            *(size_t_aX *)(out + aligned_n) = *(size_t_aX *)(in + aligned_n) ^ *(size_t_aX *)(ivec + aligned_n);
        else
            break;
    }
}
