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

extern SIPHASH *ctx;
extern unsigned int i;
extern uint64_t v0;
extern uint64_t v1;
extern uint64_t v2;
extern uint64_t v3;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t t0, t1, t2, t3;
    v0 = ctx->v0;
    v1 = ctx->v1;
    v2 = ctx->v2;
    v3 = ctx->v3;

    for (i = 0; i < ctx->drounds; ++i) {
        t0 = v0 + v1;
        t1 = (v1 << 13) | (v1 >> 51);
        t1 ^= t0;
        t0 = (t0 << 32) | (t0 >> 32);

        t2 = v2 + v3;
        t3 = (v3 << 16) | (v3 >> 48);
        t3 ^= t2;

        t0 += t3;
        t3 = (t3 << 21) | (t3 >> 43);
        t3 ^= t0;

        t2 += t1;
        t1 = (t1 << 17) | (t1 >> 47);
        t1 ^= t2;
        t2 = (t2 << 32) | (t2 >> 32);

        v0 = t0;
        v1 = t1;
        v2 = t2;
        v3 = t3;
    }

    ctx->v0 = v0;
    ctx->v1 = v1;
    ctx->v2 = v2;
    ctx->v3 = v3;
}
