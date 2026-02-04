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
    // Variant 2: Strided access with step size 2, unrolled handling for odd/even indices
    // We traverse the target region in two passes: even and odd indices
    int start = 15 - L;
    // Handle even indices
    for (unsigned int i = (start % 2 == 0) ? start : start + 1; i < 16; i += 2)
        ctx->nonce.c[i] = 0;
    // Handle odd indices
    for (unsigned int i = (start % 2 == 1) ? start : start + 1; i < 16; i += 2)
        ctx->nonce.c[i] = 0;
}
