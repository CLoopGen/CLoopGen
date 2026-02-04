#include <stdio.h>

#include <inttypes.h>

extern size_t md_block_size;
extern unsigned char hmac_pad[128];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < md_block_size; j++) {
        for (i = 0; i <= j; i++) {
            if (i < md_block_size) {
                hmac_pad[i] ^= 106;
            }
        }
    }
}
