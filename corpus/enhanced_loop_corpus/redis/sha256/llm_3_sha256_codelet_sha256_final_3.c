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
    // Variant 2: Strided memory access with reversed state processing order
    // Access the state array in reverse and write to hash with a fixed stride of 4
    for (i = 0; i < 4; ++i) {
        WORD shift = 24 - i * 8;
        hash[i + 0*4] = (ctx->state[7] >> shift) & 255;  // reversed state index
        hash[i + 1*4] = (ctx->state[6] >> shift) & 255;
        hash[i + 2*4] = (ctx->state[5] >> shift) & 255;
        hash[i + 3*4] = (ctx->state[4] >> shift) & 255;
        hash[i + 4*4] = (ctx->state[3] >> shift) & 255;
        hash[i + 5*4] = (ctx->state[2] >> shift) & 255;
        hash[i + 6*4] = (ctx->state[1] >> shift) & 255;
        hash[i + 7*4] = (ctx->state[0] >> shift) & 255;
    }
}
