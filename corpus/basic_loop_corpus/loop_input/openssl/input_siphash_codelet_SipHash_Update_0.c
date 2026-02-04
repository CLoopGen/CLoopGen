#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct siphash_st {
    uint64_t total_inlen;
    uint64_t v0;
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
    unsigned int len;
    unsigned int hash_size;
    unsigned int crounds;
    unsigned int drounds;
    unsigned char leavings[8];
};

typedef struct siphash_st SIPHASH;

SIPHASH *ctx;
unsigned char *in;
uint64_t m;
uint8_t *end;
unsigned int i;
uint64_t v0;
uint64_t v1;
uint64_t v2;
uint64_t v3;

void init_vars() {
    ctx = (SIPHASH *)malloc(sizeof(SIPHASH));
    ctx->crounds = 2;
    ctx->drounds = 4;
    ctx->len = 0;
    ctx->hash_size = 8;
    ctx->total_inlen = 0;
    ctx->v0 = 0x736f6d6570736575ULL;
    ctx->v1 = 0x646f72616e646f6dULL;
    ctx->v2 = 0x6c7967656e657261ULL;
    ctx->v3 = 0x7465646279746573ULL;
    memset(ctx->leavings, 0, 8);

    const size_t data_size = 262144; // 256 KB input
    in = (unsigned char *)malloc(data_size);
    if (!in) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (size_t j = 0; j < data_size; ++j) {
        in[j] = (unsigned char)(j & 0xFF);
    }

    end = in + data_size;
    m = 0;
    i = 0;
    v0 = ctx->v0;
    v1 = ctx->v1;
    v2 = ctx->v2;
    v3 = ctx->v3;
}