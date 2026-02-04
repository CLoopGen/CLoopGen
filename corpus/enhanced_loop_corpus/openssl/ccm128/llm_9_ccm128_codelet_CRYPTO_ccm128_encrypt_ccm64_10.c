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
    size_t unroll_factor = 4;
    size_t remainder = len % unroll_factor;
    // Unrolled loop with increased trip count handling via loop expansion
    for (i = 0; i < len - remainder; i += unroll_factor) {
        ctx->cmac.c[i] ^= inp[i];
        ctx->cmac.c[i + 1] ^= inp[i + 1];
        ctx->cmac.c[i + 2] ^= inp[i + 2];
        ctx->cmac.c[i + 3] ^= inp[i + 3];
    }
    // Handle remaining elements without additional control constructs
    for (; i < len; ++i) {
        ctx->cmac.c[i] ^= inp[i];
    }
}
