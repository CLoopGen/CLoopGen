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
    for (WORD j = 0; j < 2; ++j) {
        for (i = 0; i < 2; ++i) {
            WORD idx = j * 2 + i;
            hash[idx] = (ctx->state[0] >> (24 - idx * 8)) & 255;
            hash[idx + 4] = (ctx->state[1] >> (24 - idx * 8)) & 255;
            hash[idx + 8] = (ctx->state[2] >> (24 - idx * 8)) & 255;
            hash[idx + 12] = (ctx->state[3] >> (24 - idx * 8)) & 255;
            hash[idx + 16] = (ctx->state[4] >> (24 - idx * 8)) & 255;
            hash[idx + 20] = (ctx->state[5] >> (24 - idx * 8)) & 255;
            hash[idx + 24] = (ctx->state[6] >> (24 - idx * 8)) & 255;
            hash[idx + 28] = (ctx->state[7] >> (24 - idx * 8)) & 255;
        }
    }
}
