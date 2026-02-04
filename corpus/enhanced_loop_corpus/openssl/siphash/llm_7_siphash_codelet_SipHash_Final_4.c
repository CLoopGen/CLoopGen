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
    uint64_t a0, a1, a2, a3;
    a0 = ctx->v0;
    a1 = ctx->v1;
    a2 = ctx->v2;
    a3 = ctx->v3;

    for (i = 0; i < ctx->drounds; ++i) {
        // Introduce temporary accumulators to break and rewire dependencies
        uint64_t temp0 = a0 + a1;
        uint64_t temp1 = (a1 << 13) | (a1 >> 51);
        temp1 ^= temp0;
        uint64_t temp0_rot = (temp0 << 32) | (temp0 >> 32);

        uint64_t temp2 = a2 + a3;
        uint64_t temp3 = (a3 << 16) | (a3 >> 48);
        temp3 ^= temp2;

        uint64_t temp0_new = temp0_rot + temp3;
        temp3 = (temp3 << 21) | (temp3 >> 43);
        temp3 ^= temp0_new;

        temp2 ^= temp1;
        temp1 = (temp1 << 17) | (temp1 >> 47);
        temp1 += temp2;
        temp2 = (temp2 << 32) | (temp2 >> 32);

        // Reintroduce WAW-like pattern by updating shared temps late
        a0 = temp0_new;
        a1 = temp1;
        a2 = temp2;
        a3 = temp3;
    }

    // Final write-back to context
    ctx->v0 = a0;
    ctx->v1 = a1;
    ctx->v2 = a2;
    ctx->v3 = a3;
}
