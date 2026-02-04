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
    for (i = 0; i < 16; i += 2) {
        WORD shift1 = 24 - (i % 4) * 8;
        WORD shift2 = 24 - ((i + 1) % 4) * 8;
        BYTE val0_1 = (ctx->state[0] >> shift1) & 255;
        BYTE val0_2 = (ctx->state[0] >> shift2) & 255;
        BYTE val1_1 = (ctx->state[1] >> shift1) & 255;
        BYTE val1_2 = (ctx->state[1] >> shift2) & 255;
        hash[i + 0] = val0_1;
        hash[i + 1] = val0_2;
        hash[i + 4] = val1_1;
        hash[i + 5] = val1_2;

        if (i < 8) {
            BYTE val2_1 = (ctx->state[2] >> shift1) & 255;
            BYTE val2_2 = (ctx->state[2] >> shift2) & 255;
            BYTE val3_1 = (ctx->state[3] >> shift1) & 255;
            BYTE val3_2 = (ctx->state[3] >> shift2) & 255;
            hash[i + 8] = val2_1;
            hash[i + 9] = val2_2;
            hash[i + 12] = val3_1;
            hash[i + 13] = val3_2;
        }

        if (i < 4) {
            BYTE val4_1 = (ctx->state[4] >> shift1) & 255;
            BYTE val4_2 = (ctx->state[4] >> shift2) & 255;
            BYTE val5_1 = (ctx->state[5] >> shift1) & 255;
            BYTE val5_2 = (ctx->state[5] >> shift2) & 255;
            hash[i + 16] = val4_1;
            hash[i + 17] = val4_2;
            hash[i + 20] = val5_1;
            hash[i + 21] = val5_2;
        }

        if (i == 0) {
            hash[i + 24] = (ctx->state[6] >> shift1) & 255;
            hash[i + 25] = (ctx->state[6] >> shift2) & 255;
            hash[i + 28] = (ctx->state[7] >> shift1) & 255;
            hash[i + 29] = (ctx->state[7] >> shift2) & 255;
        }
    }
}
