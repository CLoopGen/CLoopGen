#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (md_block_size > 0) {
        hmac_pad[0] ^= 106;
        for (i = 1; i < md_block_size; i++)
            hmac_pad[i] ^= 106;
    }
}
