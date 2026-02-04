#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

extern unsigned char digest[20];
extern SHA1_CTX *context;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded trip count and additional arithmetic operations
    for (i = 0; i < 40; i++) {
        uint32_t shifted = context->state[i >> 3] >> ((7 - (i & 7)) * 4);
        digest[i >> 1] ^= (unsigned char)((shifted & 15) | ((shifted & 240) >> 4) << 4);
    }
}
