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
    for (i = 0; i < ctx->drounds; ++i) {
        uint64_t t0 = v0, t1 = v1, t2 = v2, t3 = v3;
        t0 += t1;
        t1 = (uint64_t)(((t1) << (13)) | ((t1) >> (64 - (13))));
        t1 ^= t0;
        t0 = (uint64_t)(((t0) << (32)) | ((t0) >> (64 - (32))));
        t2 += t3;
        t3 = (uint64_t)(((t3) << (16)) | ((t3) >> (64 - (16))));
        t3 ^= t2;
        t0 += t3;
        t3 = (uint64_t)(((t3) << (21)) | ((t3) >> (64 - (21))));
        t3 ^= t0;
        t2 += t1;
        t1 = (uint64_t)(((t1) << (17)) | ((t1) >> (64 - (17))));
        t1 ^= t2;
        t2 = (uint64_t)(((t2) << (32)) | ((t2) >> (64 - (32))));
        v0 = t0; v1 = t1; v2 = t2; v3 = t3;
    }
}
