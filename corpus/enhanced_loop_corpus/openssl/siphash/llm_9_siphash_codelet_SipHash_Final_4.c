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
    // Variant 2: Reduced complexity with fewer operations per iteration and conditional skipping
    if (ctx->drounds == 0) return;

    // Reduced effective trip count and simplified inner structure
    for (i = 0; i < (ctx->drounds + 1) / 2; ++i) {
        // Merge and reduce operations: only one full lane (v0, v1) updated
        v0 += v1;
        v1 = (uint64_t)(((v1) << (13)) | ((v1) >> (64 - (13))));
        v1 ^= v0;
        v0 = (uint64_t)(((v0) << (32)) | ((v0) >> (64 - (32))));

        // Lightweight update on v2/v3 without full diffusion
        v2 += v3;
        v3 ^= v2;

        // Alternate injection every other iteration to reduce work
        if (i % 2 == 0) {
            v0 += v3;
            v3 = (uint64_t)(((v3) << (21)) | ((v3) >> (64 - (21))));
            v3 ^= v0;
        }

        v2 = (uint64_t)(((v2) << (32)) | ((v2) >> (64 - (32))));
    }
}
