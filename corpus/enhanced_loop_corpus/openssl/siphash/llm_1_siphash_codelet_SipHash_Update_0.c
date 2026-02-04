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
extern  unsigned char *in;
extern uint64_t m;
extern  uint8_t *end;
extern unsigned int i;
extern uint64_t v0;
extern uint64_t v1;
extern uint64_t v2;
extern uint64_t v3;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (; in < end - 7; in += 8) {
        m = (((uint64_t)((in)[0])) | ((uint64_t)((in)[1]) << 8) | ((uint64_t)((in)[2]) << 16) | ((uint64_t)((in)[3]) << 24) | ((uint64_t)((in)[4]) << 32) | ((uint64_t)((in)[5]) << 40) | ((uint64_t)((in)[6]) << 48) | ((uint64_t)((in)[7]) << 56));
        v3 ^= m;

        if (ctx->crounds > 0) {
            for (i = 0; i < ctx->crounds; ++i) {
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
            }
        }

        v0 ^= m;
    }

    // Handle remaining bytes if any (less than 8)
    while (in != end) {
        uint64_t tail = 0;
        int shift = 0;
        const unsigned char *p = in;
        for (int j = 0; p != end && j < 8; ++j, ++p) {
            tail |= (uint64_t)(*p) << shift;
            shift += 8;
        }
        v3 ^= tail;
        for (i = 0; i < ctx->crounds; ++i) {
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
        }
        v0 ^= tail;
        break;
    }
}
