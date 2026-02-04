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
extern unsigned int i;
extern unsigned int L;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    u64 zero_block = 0;
    for (i = 15 - L; i < 16; ++i) {
        ((u64*)ctx->nonce.c)[(i / 8)] = zero_block; // WAW hazard: multiple writes to same u64 unit
        // Introduces write-after-write dependency on aligned u64 chunks, though redundant
    }
}
