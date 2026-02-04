#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

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
size_t n;
unsigned int i;
unsigned int L;

void init_vars() {
    L = 8;
    ctx = (CCM128_CONTEXT *)malloc(sizeof(CCM128_CONTEXT));
    if (!ctx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(ctx, 0, sizeof(*ctx));
    ctx->blocks = 0;
    ctx->block = NULL;
    ctx->key = NULL;
    for (int j = 0; j < 16; ++j) {
        ctx->nonce.c[j] = (u8)(j + 1);
    }
}

void loop(); 

void run_loop() {
    init_vars();
    loop();
}