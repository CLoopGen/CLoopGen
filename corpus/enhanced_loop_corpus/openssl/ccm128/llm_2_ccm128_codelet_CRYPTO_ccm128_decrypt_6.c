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
    // Variant 1: Consecutive memory access using u64 array instead of u8
    // The original loop clears the last (L+1) bytes; we now clear corresponding u64 words if needed
    u64 *n = ctx->nonce.u;
    if (L >= 8) {
        n[0] = 0;
        n[1] = 0;
    } else {
        for (unsigned int j = 0; j < 2; ++j) {
            // Clear each u64 only if any byte within it needs to be cleared
            u64 mask = 0;
            for (int b = 0; b < 8; ++b) {
                unsigned int idx = j * 8 + b;
                if (idx >= 15 - L && idx < 16)
                    mask |= (1ULL << (b * 8));
            }
            n[j] &= ~mask;
        }
    }
}
