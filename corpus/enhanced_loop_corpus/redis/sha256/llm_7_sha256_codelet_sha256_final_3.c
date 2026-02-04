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
    WORD offset;
    for (i = 0; i < 4; ++i) {
        offset = 24 - i * 8;
        hash[i]       = (ctx->state[0] >> offset) & 255;
        hash[i + 4]   = (ctx->state[1] >> offset) & 255;
        hash[i + 8]   = (ctx->state[2] >> offset) & 255;
        hash[i + 12]  = (ctx->state[3] >> offset) & 255;
        hash[i + 16]  = (ctx->state[4] >> offset) & 255;
        hash[i + 20]  = (ctx->state[5] >> offset) & 255;
        hash[i + 24]  = (ctx->state[6] >> offset) & 255;
        hash[i + 28]  = (ctx->state[7] >> offset) & 255;

        // Introduce artificial loop-carried dependency (WAW on offset, though harmless)
        offset = offset + 8; // This write does not affect correctness but creates WAW
    }
}
