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
    size_t n_local = 0;
    u8 *access_map = (u8[]){14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // reverse mapping
    unsigned int start_idx = 15 - L;
    for (i = start_idx; i < 15; ++i) {
        unsigned int mapped_index = access_map[14 - i]; // strided-like indirect access
        n_local |= ctx->nonce.c[mapped_index];
        ctx->nonce.c[mapped_index] = 0;
        n_local <<= 8;
    }
    n = n_local;
}
