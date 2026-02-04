#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp;
extern aes_block_t iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i, j;
    const size_t unroll_factor = 2;
    const size_t iterations = (16 / sizeof(unsigned long)) / unroll_factor;
    for (i = 0; i < iterations; ++i) {
        j = i * unroll_factor;
        tmp.data[j] ^= iv2.data[j];
        tmp.data[j + 1] ^= iv2.data[j + 1];
    }
    // Handle any remaining iteration if unrolling doesn't divide evenly
    if ((16 / sizeof(unsigned long)) % unroll_factor != 0)
        tmp.data[16 / sizeof(unsigned long) - 1] ^= iv2.data[16 / sizeof(unsigned long) - 1];
}
