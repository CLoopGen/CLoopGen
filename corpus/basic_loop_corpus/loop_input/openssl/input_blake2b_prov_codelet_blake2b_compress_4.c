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

    memset(S->h, 0, sizeof(S->h));
    memset(S->t, 0, sizeof(S->t));
    memset(S->f, 0, sizeof(S->f));
    memset(S->buf, 0, sizeof(S->buf));
    S->buflen = 0;
    S->outlen = 64;

    for (int j = 0; j < 16; ++j) {
        v[j] = j * 0xdeadbeefULL + 0xcafebabeULL;
    }
}