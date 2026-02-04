#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct blake2b_ctx_st {
    uint64_t h[8];
    uint64_t t[2];
    uint64_t f[2];
    uint8_t buf[128];
    size_t buflen;
    size_t outlen;
};

typedef struct blake2b_ctx_st BLAKE2B_CTX;

BLAKE2B_CTX *S;
uint64_t v[16];
int i;

void init_vars() {
    S = (BLAKE2B_CTX *)malloc(sizeof(BLAKE2B_CTX));
    if (!S) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 8; ++j) {
        S->h[j] = 0x10000000 + j;
    }

    S->t[0] = 0;
    S->t[1] = 0;
    S->f[0] = 0xFFFFFFFFFFFFFFFFULL;
    S->f[1] = 0xFFFFFFFFFFFFFFFFULL;
    memset(S->buf, 0xAA, 128);
    S->buflen = 0;
    S->outlen = 64;

    for (int j = 0; j < 16; ++j) {
        v[j] = 0;
    }

    i = 0;
}