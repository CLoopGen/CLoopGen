#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 48; i++) {
        int idx = i % 16;
        dst[idx] ^= src[idx] ^ iv[idx] ^ (src[idx] >> 1) ^ (iv[idx] << 1);
    }
}
