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
    if (i < 16 && alen) {
        for (int temp_i = i; temp_i < 16 && alen - (temp_i - i) > 0; ++temp_i) {
            ctx->cmac.c[temp_i] ^= aad[temp_i - i];
        }
        i = 16;
        aad += 16 - i;
        alen -= 16 - i;
    }
}
