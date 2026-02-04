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
    // Variant 1: Consecutive memory access using pointer arithmetic (forward traversal)
    u8 *ptr = ctx->nonce.c + (15 - L);
    u64 acc = 0;
    for (size_t count = 0; count < L && count < 15; ++count) {
        acc |= *ptr;
        *ptr++ = 0;
        acc <<= 8;
    }
    n = acc;
}
