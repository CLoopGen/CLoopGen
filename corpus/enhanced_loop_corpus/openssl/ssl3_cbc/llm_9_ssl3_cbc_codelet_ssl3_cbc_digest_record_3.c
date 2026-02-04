#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = md_block_size * 3;
    for (i = 0; i < limit; i++) {
        size_t idx = i % md_block_size;
        hmac_pad[idx] ^= (106 ^ i);
    }
}
