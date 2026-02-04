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

extern CCM128_CONTEXT *ctx;
extern size_t n;
extern unsigned int i;
extern unsigned int L;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reverse traversal
    // Instead of accessing ctx->nonce.c[i] in increasing index from (15-L) to 14,
    // we reverse the order and access consecutively from high to low.
    n = 0;
    u8 *ptr = ctx->nonce.c + 15 - L;
    for (i = 0; i < L && (15 - L + i) < 15; ++i) {
        n |= ptr[i];
        ptr[i] = 0;
        n <<= 8;
    }
}
