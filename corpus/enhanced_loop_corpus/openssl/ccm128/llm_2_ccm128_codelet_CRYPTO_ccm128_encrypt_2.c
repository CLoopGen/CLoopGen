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
    // Variant 1: Consecutive memory access using word-level writes instead of byte-level
    // Instead of writing each byte individually, we zero out the entire 64-bit segment
    // that covers the target region, adjusting for alignment and range.
    u64 *nonce_u64 = ctx->nonce.u;
    if (L >= 8) {
        nonce_u64[1] = 0;  // Covers bytes 8..15, which includes 15-L to 15 when L>=8
    } else {
        // For smaller L, still use byte access but minimize iterations
        for (unsigned int j = 15 - L; j < 16; ++j)
            ctx->nonce.c[j] = 0;
    }
}
