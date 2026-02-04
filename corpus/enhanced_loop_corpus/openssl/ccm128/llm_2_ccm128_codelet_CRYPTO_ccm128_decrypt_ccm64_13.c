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
    // The original loop zeroes bytes from index (15-L) to 15.
    // We reinterpret the same memory as u64 and zero up to two 8-byte chunks if needed.
    u64 start_offset = 15 - L;
    if (start_offset < 8) {
        ctx->nonce.u[0] = 0;
        if (start_offset <= 8) {
            ctx->nonce.u[1] = 0;
        } else {
            // Only part of u[1] needs zeroing, so fallback byte-wise for tail
            for (unsigned int j = start_offset; j < 16; ++j)
                ctx->nonce.c[j] = 0;
        }
    } else {
        // Only affects second u64 block
        for (unsigned int j = start_offset; j < 16; ++j)
            ctx->nonce.c[j] = 0;
    }
}
