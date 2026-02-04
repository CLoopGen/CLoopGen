#include <stdio.h>
#include <inttypes.h>

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
unsigned int i;
uint64_t v0;
uint64_t v1;
uint64_t v2;
uint64_t v3;

static SIPHASH ctx_storage;

void init_vars() {
    ctx = &ctx_storage;
    ctx->crounds = 8;  // typical value for SipHash rounds
    ctx->drounds = 4;
    ctx->total_inlen = 0;
    ctx->len = 0;
    ctx->hash_size = 8;
    ctx->v0 = 0x736f6d6570736575ULL;
    ctx->v1 = 0x646f72616e646f6dULL;
    ctx->v2 = 0x6c7967656e657261ULL;
    ctx->v3 = 0x7465646279746573ULL;
    for (int j = 0; j < 8; ++j)
        ctx->leavings[j] = 0;

    v0 = ctx->v0;
    v1 = ctx->v1;
    v2 = ctx->v2;
    v3 = ctx->v3;
}