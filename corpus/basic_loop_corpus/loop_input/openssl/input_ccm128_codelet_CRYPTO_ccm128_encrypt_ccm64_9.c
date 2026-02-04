#include <stdio.h>
#include <inttypes.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union cipher_data {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union cipher_data nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

static CCM128_CONTEXT ctx_storage;
CCM128_CONTEXT *ctx = &ctx_storage;
unsigned int i;
unsigned int L = 4; // Ensures loop runs from 15 - 4 = 11 to 15 (5 iterations)

void init_vars() {
    ctx = &ctx_storage;
    ctx->blocks = 0;
    ctx->block = NULL;
    ctx->key = NULL;
    for (int j = 0; j < 16; ++j) {
        ctx->nonce.c[j] = j + 1;
        ctx->cmac.c[j] = j + 17;
    }
}