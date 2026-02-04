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
    size_t n = 0;
    unsigned int i = 15 - L;
    u8 *nonce_ptr = ctx->nonce.c;

    for (; i < 15; ++i) {
        n |= *(nonce_ptr + i);
        *(nonce_ptr + i) = 0;
        n <<= 8;
    }
}
