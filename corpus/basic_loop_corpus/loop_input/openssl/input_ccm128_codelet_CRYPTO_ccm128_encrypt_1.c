#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union byte_u {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union byte_u nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

CCM128_CONTEXT *ctx;
size_t n;
unsigned int i;
unsigned int L = 4; // chosen so that 15-L is within bounds [0,15]

void init_vars() {
    ctx = (CCM128_CONTEXT *)aligned_alloc(16, sizeof(CCM128_CONTEXT));
    if (!ctx) exit(1);
    memset(ctx, 0, sizeof(CCM128_CONTEXT));

    // Initialize nonce with non-zero test pattern
    for (int j = 0; j < 16; ++j) {
        ctx->nonce.c[j] = (u8)(j + 1);
    }

    L = 4; // ensures i starts at 11, loops from 11 to 14 inclusive
}