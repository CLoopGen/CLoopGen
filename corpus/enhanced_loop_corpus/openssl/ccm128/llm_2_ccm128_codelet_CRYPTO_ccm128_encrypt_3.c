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
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t aligned_len = len & ~1U; // Round down to nearest even number
    for (i = 0; i < aligned_len; i += 2) {
        ctx->cmac.c[i] ^= inp[i];
        ctx->cmac.c[i + 1] ^= inp[i + 1];
    }
    // Handle remaining element if length is odd
    if (len & 1) {
        ctx->cmac.c[len - 1] ^= inp[len - 1];
    }
}
