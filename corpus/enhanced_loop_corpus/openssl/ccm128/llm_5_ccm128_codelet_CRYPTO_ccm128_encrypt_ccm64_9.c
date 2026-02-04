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
    u8 temp[16];
    for (i = 15 - L; i < 16; ++i) {
        temp[i] = ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
    }
    // Introduces temporary storage, creating a WAR dependency between temp[i] and ctx->nonce.c[i]
    // Also introduces a new data flow: old value saved before overwrite (WAW-like via temp)
}
