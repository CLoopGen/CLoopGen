#include <stdio.h>

#include <inttypes.h>

extern unsigned int i;
extern unsigned char hmac_key[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < sizeof(hmac_key); i += 2) {
        hmac_key[i] ^= 54;
        if (i + 1 < sizeof(hmac_key)) {
            hmac_key[i + 1] ^= 54;
        }
    }
}
