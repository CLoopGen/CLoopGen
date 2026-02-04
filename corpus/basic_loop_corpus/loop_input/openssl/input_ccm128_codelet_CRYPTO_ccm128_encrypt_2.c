#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union {
        u64 u[2];
        u8 c[16];
    } nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

CCM128_CONTEXT *ctx;
unsigned int i;
unsigned int L = 4;

static CCM128_CONTEXT ctx_storage;

void init_vars() {
    ctx = &ctx_storage;
    L = 4;
    memset(ctx->nonce.c, 0, 16);
    memset(ctx->cmac.c, 0, 16);
    ctx->blocks = 0;
    ctx->block = NULL;
    ctx->key = NULL;
}