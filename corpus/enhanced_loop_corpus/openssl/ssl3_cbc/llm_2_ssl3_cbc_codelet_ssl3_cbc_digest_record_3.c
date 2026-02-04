#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < md_block_size; i += 2)
        hmac_pad[i] ^= 106;
    // Handle potential odd-sized block to maintain correctness
    if (md_block_size % 2 == 1) {
        for (i = 1; i < md_block_size; i += 2)
            hmac_pad[i] ^= 106;
    }
}
