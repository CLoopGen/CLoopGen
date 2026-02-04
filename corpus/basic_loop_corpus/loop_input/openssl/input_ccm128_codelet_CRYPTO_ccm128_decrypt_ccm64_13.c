#include <stdio.h>
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
unsigned int i;
unsigned int L = 4; // Ensures loop runs from 11 to 15 (valid range)

static CCM128_CONTEXT ctx_storage;
static u8 dummy_block_output[16];
static u8 dummy_input[16];

void dummy_block_func(const unsigned char *in, unsigned char *out, const void *key) {
    for (int j = 0; j < 16; ++j)
        out[j] = in[j] ^ ((const unsigned char *)key)[j];
}

void init_vars() {
    ctx = &ctx_storage;
    ctx->blocks = 0;
    ctx->key = (void *)dummy_input;
    ctx->block = dummy_block_func;
    
    L = 4; // Set L so that 15-L = 11, loop runs from 11 to 15 inclusive
    
    for (int j = 0; j < 16; ++j) {
        ctx->nonce.c[j] = j + 1;
        ctx->cmac.c[j] = j + 17;
        dummy_input[j] = j * 3;
        dummy_block_output[j] = 0;
    }
}