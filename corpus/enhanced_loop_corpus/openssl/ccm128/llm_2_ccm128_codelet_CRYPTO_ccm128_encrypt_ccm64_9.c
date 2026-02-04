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
    // Variant 2: Strided memory access with reverse iteration (stride of 2)
    // We traverse the array in reverse order with a step size of 2 (strided access),
    // handling odd-sized ranges by adjusting the starting point.

    unsigned int start = 15 - L;
    unsigned int end = 16;

    // Adjust starting index for strided pattern (even indices only in this stride)
    unsigned int i = (end - 1) | 1;  // Start from last odd index <= 15
    for (; i >= start && i < 16; i -= 2) {
        ctx->nonce.c[i] = 0;
        if (i > start && (i - 1) < 16) {
            ctx->nonce.c[i - 1] = 0;
        }
    }
}
