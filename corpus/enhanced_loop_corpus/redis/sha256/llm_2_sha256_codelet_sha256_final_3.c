#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint8_t BYTE;

typedef uint32_t WORD;

typedef struct {
    BYTE data[64];
    WORD datalen;
    unsigned long long bitlen;
    WORD state[8];
} SHA256_CTX;

extern SHA256_CTX *ctx;
extern BYTE hash[];
extern WORD i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    // Instead of calculating indices repeatedly, use a pointer to traverse hash consecutively
    BYTE *h = hash;
    for (i = 0; i < 4; ++i) {
        WORD shift = 24 - i * 8;
        *h++ = (ctx->state[0] >> shift) & 255;
        *h++ = (ctx->state[1] >> shift) & 255;
        *h++ = (ctx->state[2] >> shift) & 255;
        *h++ = (ctx->state[3] >> shift) & 255;
        *h++ = (ctx->state[4] >> shift) & 255;
        *h++ = (ctx->state[5] >> shift) & 255;
        *h++ = (ctx->state[6] >> shift) & 255;
        *h++ = (ctx->state[7] >> shift) & 255;
    }
}
