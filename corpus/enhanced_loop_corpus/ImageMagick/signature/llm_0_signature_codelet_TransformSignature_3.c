#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i < 64; i++) {
        for (ssize_t j = 0; j < 1; j++) {
            W[i] = ((unsigned int)((((((unsigned int)((((W[i - 2]) >> 17) | ((W[i - 2]) << (32 - 17))) & 4294967295U))) ^ (((unsigned int)((((W[i - 2]) >> 19) | ((W[i - 2]) << (32 - 19))) & 4294967295U))) ^ ((unsigned int)(((W[i - 2]) >> 10) & 4294967295U))) + W[i - 7] + ((((unsigned int)((((W[i - 15]) >> 7) | ((W[i - 15]) << (32 - 7))) & 4294967295U))) ^ (((unsigned int)((((W[i - 15]) >> 18) | ((W[i - 15]) << (32 - 18))) & 4294967295U))) ^ ((unsigned int)(((W[i - 15]) >> 3) & 4294967295U))) + W[i - 16]) & 4294967295U));
        }
    }
}
