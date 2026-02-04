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
    uint64_t local_v0 = v0, local_v1 = v1, local_v2 = v2, local_v3 = v3;
    for (i = 0; i < ctx->drounds; ++i) {
        local_v0 += local_v1;
        local_v1 = (uint64_t)(((local_v1) << (13)) | ((local_v1) >> (64 - (13))));
        local_v1 ^= local_v0;
        local_v0 = (uint64_t)(((local_v0) << (32)) | ((local_v0) >> (64 - (32))));

        local_v2 += local_v3;
        local_v3 = (uint64_t)(((local_v3) << (16)) | ((local_v3) >> (64 - (16))));
        local_v3 ^= local_v2;

        local_v0 += local_v3;
        local_v3 = (uint64_t)(((local_v3) << (21)) | ((local_v3) >> (64 - (21))));
        local_v3 ^= local_v0;

        local_v2 += local_v1;
        local_v1 = (uint64_t)(((local_v1) << (17)) | ((local_v1) >> (64 - (17))));
        local_v1 ^= local_v2;
        local_v2 = (uint64_t)(((local_v2) << (32)) | ((local_v2) >> (64 - (32))));
    }
    v0 = local_v0; v1 = local_v1; v2 = local_v2; v3 = local_v3;
}
