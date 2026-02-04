#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union byte_u64_union {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union byte_u64_union nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

CCM128_CONTEXT *ctx;
size_t n;
unsigned int i;
unsigned int L;

void init_vars() {
    L = 4; 
    ctx = (CCM128_CONTEXT *)malloc(sizeof(CCM128_CONTEXT));
    if (!ctx) return;

    ctx->blocks = 0;
    ctx->block = NULL;
    ctx->key = NULL;

    for (int j = 0; j < 16; ++j) {
        ctx->nonce.c[j] = (u8)(j + 1);
    }
}