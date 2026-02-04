#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long long u64;
typedef unsigned char u8;

union cipher_block {
    u64 u[2];
    u8 c[16];
};

typedef void (*block128_f)(const unsigned char *, unsigned char *, const void *);

struct ccm128_context {
    union cipher_block nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};

typedef struct ccm128_context CCM128_CONTEXT;

static CCM128_CONTEXT ctx_instance;
CCM128_CONTEXT *ctx = &ctx_instance;
size_t n;
unsigned int i;
unsigned int L = 4; // chosen so that 15-L is in valid range [0,14]

void init_vars() {
    L = 4;
    memset(&ctx_instance, 0, sizeof(ctx_instance));
    for (int j = 0; j < 16; ++j) {
        ctx_instance.nonce.c[j] = (u8)(j + 1);
    }
    ctx_instance.blocks = 0;
    ctx_instance.key = NULL;
    ctx_instance.block = NULL;
}