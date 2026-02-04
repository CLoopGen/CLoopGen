#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t step = 2;
    for (i = 0; i < md_block_size; i += step) {
        hmac_pad[i] ^= 54;
    }
    // Handle any remaining element if md_block_size is odd
    if (md_block_size % 2 == 1) {
        hmac_pad[md_block_size - 1] ^= 54;
    }
}
