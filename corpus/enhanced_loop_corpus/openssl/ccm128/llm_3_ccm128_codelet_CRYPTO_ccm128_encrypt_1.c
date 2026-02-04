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
    // Variant 2: Strided memory access with reverse traversal and stride of 2 (simulated pattern)
    // Only accessing every other byte in descending order, still covering the required range
    n = 0;
    int stride = 2;
    int start = 15 - L;
    // Adjust start if needed to ensure coverage within bounds
    if ((15 - start) % stride != 0) {
        start += (stride - (15 - start) % stride);
    }
    for (int i = 14; i >= (int)(15 - L); i -= stride) {
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
        // Simulate strided behavior: zero out intermediate element if in range
        if (i > (int)(15 - L)) {
            ctx->nonce.c[i - 1] = 0;
            n <<= 8;
        }
    }
    // Final shift compensation if odd number of effective operations
    if (L % 2 == 1) {
        n <<= 8;
    }
}
