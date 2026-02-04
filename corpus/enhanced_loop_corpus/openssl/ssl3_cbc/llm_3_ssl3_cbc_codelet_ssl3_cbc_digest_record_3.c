#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = md_block_size; i > 0; --i)
        hmac_pad[i - 1] ^= 106;
}
