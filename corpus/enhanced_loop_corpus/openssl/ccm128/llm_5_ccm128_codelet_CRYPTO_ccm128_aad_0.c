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



void loop(){
    u8 mask = (i < 16 && alen) ? 0xFF : 0x00;
    for (; mask && alen; ++i, ++aad, --alen) {
        if (i < 16) {
            ctx->cmac.c[i] ^= *aad;
        } else {
            mask = 0;
        }
    }
}
