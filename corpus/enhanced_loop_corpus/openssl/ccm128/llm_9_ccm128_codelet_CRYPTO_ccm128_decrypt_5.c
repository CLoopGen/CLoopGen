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
    for (n = 0, i = 15 - L; i < 15; i += 2) {
        n |= ctx->nonce.c[i];
        if (i + 1 < 15) {
            n |= ((u64)ctx->nonce.c[i + 1]) << 8;
        }
        ctx->nonce.c[i] = 0;
        if (i + 1 < 15) {
            ctx->nonce.c[i + 1] = 0;
        }
        n <<= 16;
    }
}
