#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

CCM128_CONTEXT *ctx;
unsigned char *aad;
size_t alen;
unsigned int i;

void init_vars() {
    ctx = (CCM128_CONTEXT *)malloc(sizeof(CCM128_CONTEXT));
    memset(ctx, 0, sizeof(CCM128_CONTEXT));

    size_t data_size = 1024 * 128;
    aad = (unsigned char *)malloc(data_size);
    for (size_t j = 0; j < data_size; ++j) {
        aad[j] = (unsigned char)(j & 0xFF);
    }

    alen = data_size;
    i = 0;
}