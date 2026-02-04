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
extern  unsigned char *inp;
extern size_t len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < len && i < 16; ++i) {
        ctx->cmac.c[i] ^= inp[i];
        ctx->cmac.c[i] += (ctx->cmac.c[i] << 1); // Additional arithmetic to increase computational intensity
    }
}
