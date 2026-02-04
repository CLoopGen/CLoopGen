#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern AVXTEA *ctx;
extern  uint8_t key[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        uint32_t temp = ((const union unaligned_32 *)(key + (i << 2)))->l;
        ctx->key[i] = temp ^ 0x5A5A5A5A; // Increased arithmetic intensity with XOR
        ctx->key[15 - i] = temp ^ 0xA5A5A5A5;
    }
}
