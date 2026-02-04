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
extern  unsigned char *aad;
extern size_t alen;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access — process every 2nd byte forward, then handle remainder if needed
    size_t stride = 2;
    size_t limit = (alen > 16 - i) ? 16 - i : alen;
    for (size_t j = 0; j < limit; j += stride) {
        ctx->cmac.c[i + j] ^= aad[j];
        if (j + 1 < limit) {
            ctx->cmac.c[i + j + 1] ^= aad[j + 1];
        }
    }
    // Update shared state only once after loop
    i += limit;
    aad += limit;
    alen -= limit;
}
