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
    // Variant 2: Strided memory access (stride of 1 byte instead of 4, processing byte-wise reconstruction)
    for (i = 0; i < 4; i++) {
        uint32_t val = 0;
        const uint8_t *src = key + (i << 2); // Base address for each 32-bit chunk
        val |= ((uint32_t)src[0]) << 0;
        val |= ((uint32_t)src[1]) << 8;
        val |= ((uint32_t)src[2]) << 16;
        val |= ((uint32_t)src[3]) << 24;
        ctx->key[i] = val;
    }
}
