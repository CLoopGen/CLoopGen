#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct blake2s_ctx_st {
    uint32_t h[8];
    uint32_t t[2];
    uint32_t f[2];
    uint8_t buf[64];
    size_t buflen;
    size_t outlen;
};

typedef struct blake2s_ctx_st BLAKE2S_CTX;

BLAKE2S_CTX *S;
uint32_t v[16];
size_t i;

void init_vars() {
    S = (BLAKE2S_CTX*)malloc(sizeof(BLAKE2S_CTX));
    if (!S) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    S->buflen = 0;
    S->outlen = 32;
    for (int j = 0; j < 8; ++j) {
        S->h[j] = 0x6A09E667U ^ j;
    }
    for (int j = 0; j < 2; ++j) {
        S->t[j] = 0;
        S->f[j] = 0xFFFFFFFFU;
    }
    memset(S->buf, 0, 64);

    for (int j = 0; j < 16; ++j) {
        v[j] = 0x71BE3D7BUL + (j * 0x9E3779B9U);
    }

    i = 0;
}