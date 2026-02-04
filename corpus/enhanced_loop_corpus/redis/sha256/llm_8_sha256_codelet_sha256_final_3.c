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
    for (i = 0; i < 8; ++i) {
        WORD shift = 24 - (i % 4) * 8;
        hash[i * 4 + 0] = (ctx->state[0] >> shift) & 255;
        if (i >= 4) continue;
        hash[i + 4] = (ctx->state[1] >> shift) & 255;
        hash[i + 8] = (ctx->state[2] >> shift) & 255;
        hash[i + 12] = (ctx->state[3] >> shift) & 255;
        hash[i + 16] = (ctx->state[4] >> shift) & 255;
        hash[i + 20] = (ctx->state[5] >> shift) & 255;
        hash[i + 24] = (ctx->state[6] >> shift) & 255;
        hash[i + 28] = (ctx->state[7] >> shift) & 255;
    }
}
