#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct blake2s_ctx_st {
    uint32_t h[8];
    uint32_t t[2];
    uint32_t f[2];
    uint8_t buf[64];
    size_t buflen;
    size_t outlen;
};

typedef struct blake2s_ctx_st BLAKE2S_CTX;

uint32_t blake2s_IV[8] = {
    0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
    0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
};

BLAKE2S_CTX *S;
int i;

void init_vars() {
    S = malloc(sizeof(BLAKE2S_CTX));
    if (!S) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    S->buflen = 0;
    S->outlen = 32;
}