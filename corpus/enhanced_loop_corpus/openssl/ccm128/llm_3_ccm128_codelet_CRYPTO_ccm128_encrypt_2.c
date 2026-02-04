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
    // Variant 2: Strided memory access with reverse traversal (stride of 2 forward after reversing)
    // Traverse from high to low index, but only write every other byte in two passes
    unsigned int start = 15 - L;
    unsigned int end = 16;

    // First pass: reverse order, even offsets relative to end
    for (unsigned int j = end - 1; j >= start && j < 16; j -= 2)
        ctx->nonce.c[j] = 0;

    // Second pass: handle odd offsets
    if (start <= end - 2) {
        for (unsigned int j = end - 2; j >= start && j < 16; j -= 2)
            ctx->nonce.c[j] = 0;
    }
}
