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
    WORD temp[8];
    for (i = 0; i < 4; ++i) {
        temp[0] = ctx->state[0];
        temp[1] = ctx->state[1];
        temp[2] = ctx->state[2];
        temp[3] = ctx->state[3];
        temp[4] = ctx->state[4];
        temp[5] = ctx->state[5];
        temp[6] = ctx->state[6];
        temp[7] = ctx->state[7];

        hash[i]       = (temp[0] >> (24 - i * 8)) & 255;
        hash[i + 4]   = (temp[1] >> (24 - i * 8)) & 255;
        hash[i + 8]   = (temp[2] >> (24 - i * 8)) & 255;
        hash[i + 12]  = (temp[3] >> (24 - i * 8)) & 255;
        hash[i + 16]  = (temp[4] >> (24 - i * 8)) & 255;
        hash[i + 20]  = (temp[5] >> (24 - i * 8)) & 255;
        hash[i + 24]  = (temp[6] >> (24 - i * 8)) & 255;
        hash[i + 28]  = (temp[7] >> (24 - i * 8)) & 255;
    }
}
