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
    for (; in != end; in += 8) {
        m = (((uint64_t)((in)[0])) | ((uint64_t)((in)[1]) << 8) | ((uint64_t)((in)[2]) << 16) | ((uint64_t)((in)[3]) << 24) | ((uint64_t)((in)[4]) << 32) | ((uint64_t)((in)[5]) << 40) | ((uint64_t)((in)[6]) << 48) | ((uint64_t)((in)[7]) << 56));
        v3 ^= m;

        uint64_t temp_v0 = v0, temp_v1 = v1, temp_v2 = v2, temp_v3 = v3;

        for (i = 0; i < ctx->crounds; ++i) {
            temp_v0 += temp_v1;
            temp_v1 = (uint64_t)(((temp_v1) << 13) | (temp_v1 >> 51));
            temp_v1 ^= temp_v0;
            temp_v0 = (uint64_t)(((temp_v0) << 32) | (temp_v0 >> 32));
            temp_v2 += temp_v3;
            temp_v3 = (uint64_t)(((temp_v3) << 16) | (temp_v3 >> 48));
            temp_v3 ^= temp_v2;
            temp_v0 += temp_v3;
            temp_v3 = (uint64_t)(((temp_v3) << 21) | (temp_v3 >> 43));
            temp_v3 ^= temp_v0;
            temp_v2 += temp_v1;
            temp_v1 = (uint64_t)(((temp_v1) << 17) | (temp_v1 >> 47));
            temp_v1 ^= temp_v2;
            temp_v2 = (uint64_t)(((temp_v2) << 32) | (temp_v2 >> 32));
        }

        v0 = temp_v0;
        v1 = temp_v1;
        v2 = temp_v2;
        v3 = temp_v3;
        v0 ^= m;
    }
}
