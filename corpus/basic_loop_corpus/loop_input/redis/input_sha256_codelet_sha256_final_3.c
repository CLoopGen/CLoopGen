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

SHA256_CTX *ctx;
BYTE hash[32];
WORD i;

void init_vars() {
    ctx = (SHA256_CTX*)malloc(sizeof(SHA256_CTX));
    if (!ctx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    ctx->datalen = 0;
    ctx->bitlen = 0;
    for (WORD j = 0; j < 8; ++j) {
        ctx->state[j] = 0xdeadbeef ^ (j << 20);
    }
    for (WORD j = 0; j < 64; ++j) {
        ctx->data[j] = j & 0xFF;
    }

    for (int j = 0; j < 32; ++j) {
        hash[j] = 0;
    }
}