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
    size_t n = 0;
    unsigned int indices[] = {15-L, 16-L, 17-L, 18-L, 19-L, 20-L, 21-L, 22-L, 23-L, 24-L};
    unsigned int count = 0;
    const unsigned int max_access = (15 - (15 - L)) < 10 ? (15 - (15 - L)) : 10;

    for (; count < max_access; ++count) {
        unsigned int i = indices[count];
        if (i >= 15) break;
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
    }
}
