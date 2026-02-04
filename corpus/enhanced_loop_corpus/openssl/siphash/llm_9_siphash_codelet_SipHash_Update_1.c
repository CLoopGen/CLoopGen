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
    unsigned int rounds = ctx->crounds / 2;
    if (ctx->crounds < 2) rounds = ctx->crounds;

    for (i = 0; i < rounds; ++i) {
        // Reduced version of the original round function with fewer operations
        v0 += v1;
        v1 = (uint64_t)(((v1) << (13)) | ((v1) >> (64 - (13))));
        v1 ^= v0;

        v2 += v3;
        v3 = (uint64_t)(((v3) << (16)) | ((v3) >> (64 - (16))));
        v3 ^= v2;

        v0 += v3;
        v3 ^= v0;

        v2 += v1;
        v1 ^= v2;

        // Skip some diffusion steps to reduce complexity
    }

    // Finalization-like step to maintain some structure
    v0 ^= v2;
    v1 ^= v3;
}
