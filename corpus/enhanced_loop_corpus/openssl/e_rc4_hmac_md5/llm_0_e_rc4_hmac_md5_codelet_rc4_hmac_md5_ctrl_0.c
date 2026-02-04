#include <stdio.h>

#include <inttypes.h>

extern unsigned int i;
extern unsigned char hmac_key[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < 2; j++) {
        for (i = 0; i < sizeof(hmac_key); i++)
            hmac_key[i] ^= 54;
    }
}
