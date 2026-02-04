#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct blake2b_ctx_st {
    uint64_t h[8];
    uint64_t t[2];
    uint64_t f[2];
    uint8_t buf[128];
    size_t buflen;
    size_t outlen;
};

typedef struct blake2b_ctx_st BLAKE2B_CTX;

uint64_t blake2b_IV[8] = {
    0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
    0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
    0x510e527fade682d1, 0x9b05688c2b3e6c1f,
    0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

BLAKE2B_CTX *S;
int i;

void init_vars() {
    S = malloc(sizeof(BLAKE2B_CTX));
    if (!S) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    S->buflen = 0;
    S->outlen = 64;
}