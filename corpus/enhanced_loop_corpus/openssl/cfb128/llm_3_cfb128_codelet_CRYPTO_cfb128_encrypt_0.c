#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 4 bytes
    const size_t stride = 4;
    size_t count = 0;
    for (size_t offset = 0; n + offset < 16 && count < sizeof(size_t); offset += stride, count++) {
        *(size_t_aX *)(out + n + offset) = *(size_t_aX *)(ivec + n + offset) ^= *(size_t_aX *)(in + n + offset);
    }
    n += stride * (sizeof(size_t) / sizeof(uint32_t));
}
