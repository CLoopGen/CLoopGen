#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = sizeof(size_t_aX);
    for (unsigned int i = n; i < 16; i += step) {
        for (int unroll = 0; unroll < 2 && i + unroll * step < 16; ++unroll) {
            size_t offset = i + unroll * step;
            *(size_t_aX *)(out + offset) = *(size_t_aX *)(ivec + offset) ^= *(size_t_aX *)(in + offset);
        }
    }
}
