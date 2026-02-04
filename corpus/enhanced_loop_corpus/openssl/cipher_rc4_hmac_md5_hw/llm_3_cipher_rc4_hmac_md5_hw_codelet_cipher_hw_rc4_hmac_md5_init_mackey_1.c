#include <stdio.h>

#include <inttypes.h>

extern unsigned int i;
extern unsigned char hmac_key[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = sizeof(hmac_key) - 1; i != (unsigned int)-1; i--) {
        hmac_key[i] ^= 54 ^ 92;
    }
}
