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
    // Variant 2: Introduce strided memory-like access via round scheduling
    // Simulate a strided processing pattern by grouping operations in chunks
    // and changing the order of updates to mimic non-sequential state evolution.
    // This reflects a transformed computational access pattern even without arrays.

    unsigned int rounds = ctx->crounds;
    uint64_t temp[4];

    // Stride: process rounds in groups of 2 if possible, otherwise single
    for (i = 0; i < rounds; i += 2) {
        // First "strided" round
        temp[0] = v0 + v1;
        temp[1] = ((v1 << 13) | (v1 >> 51)) ^ temp[0];
        temp[0] = ((temp[0] << 32) | (temp[0] >> 32));
        temp[2] = v2 + v3;
        temp[3] = ((v3 << 16) | (v3 >> 48)) ^ temp[2];
        temp[0] += temp[3];
        temp[3] = ((temp[3] << 21) | (temp[3] >> 43)) ^ temp[0];
        temp[2] += temp[1];
        temp[1] = ((temp[1] << 17) | (temp[1] >> 47)) ^ temp[2];
        temp[2] = (temp[2] << 32) | (temp[2] >> 32);

        // Write back after first round
        v0 = temp[0]; v1 = temp[1]; v2 = temp[2]; v3 = temp[3];

        // Second round if applicable (strided continuation)
        if (i + 1 < rounds) {
            v0 += v1;
            v1 = (v1 << 13) | (v1 >> 51);
            v1 ^= v0;
            v0 = (v0 << 32) | (v0 >> 32);
            v2 += v3;
            v3 = (v3 << 16) | (v3 >> 48);
            v3 ^= v2;
            v0 += v3;
            v3 = (v3 << 21) | (v3 >> 43);
            v3 ^= v0;
            v2 += v1;
            v1 = (v1 << 17) | (v1 >> 47);
            v1 ^= v2;
            v2 = (v2 << 32) | (v2 >> 32);
        }
    }
}
