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
    // Variant 2: Memory Access Pattern Modification using indirect access via index array
    // Simulate indirect memory access using an index remapping table to alter access order.
    // This models irregular memory patterns common in sparse computations.

    uint64_t dummy_data[8];
    unsigned int index_map[8];

    // Initialize data
    for (unsigned int j = 0; j < 8; ++j) {
        dummy_data[j] = j * j + 1;
        index_map[j] = (5 * j + 3) % 8; // Indirect index mapping: pseudo-random permutation
    }

    v0 = ctx->v0;
    v1 = ctx->v1;
    v2 = ctx->v2;
    v3 = ctx->v3;

    for (i = 0; i < ctx->drounds; ++i) {
        v0 += v1;
        v1 = (uint64_t)(((v1) << (13)) | ((v1) >> (64 - (13))));
        v1 ^= v0;
        v0 = (uint64_t)(((v0) << (32)) | ((v0) >> (64 - (32))));
        v2 += v3;
        v3 = (uint64_t)(((v3) << (16)) | ((v3) >> (64 - (16))));
        v3 ^= v2;
        v0 += v3;
        v3 = (uint64_t)(((v3) << (21)) | ((v3) >> (64 - (21))));
        v3 ^= v0;
        v2 += v1;
        v1 = (uint64_t)(((v1) << (17)) | ((v1) >> (64 - (17))));
        v1 ^= v2;
        v2 = (uint64_t)(((v2) << (32)) | ((v2) >> (64 - (32))));

        // Apply indirect memory access using remapped indices
        for (unsigned int j = 0; j < 8; ++j) {
            unsigned int idx = index_map[j]; // Indirect access
            v0 ^= dummy_data[idx] & 0xFF;
            v3 ^= (dummy_data[idx] >> 32) & 0xFF;
        }
    }

    ctx->v0 = v0;
    ctx->v1 = v1;
    ctx->v2 = v2;
    ctx->v3 = v3;
}
