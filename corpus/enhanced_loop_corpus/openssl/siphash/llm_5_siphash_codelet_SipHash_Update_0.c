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



void loop(){
    for (; in != end; in += 8) {
        m = (((uint64_t)((in)[0])) | ((uint64_t)((in)[1]) << 8) | ((uint64_t)((in)[2]) << 16) | ((uint64_t)((in)[3]) << 24) | ((uint64_t)((in)[4]) << 32) | ((uint64_t)((in)[5]) << 40) | ((uint64_t)((in)[6]) << 48) | ((uint64_t)((in)[7]) << 56));

        if ((in[0] & 0x1) == 0) {
            v3 ^= m;
            for (i = 0; i < ctx->crounds; ++i) {
                v0 += v1;
                v1 = (uint64_t)(((v1) << 13) | ((v1) >> 51));
                v1 ^= v0;
                v0 = (uint64_t)(((v0) << 32) | ((v0) >> 32));
                v2 += v3;
                v3 = (uint64_t)(((v3) << 16) | ((v3) >> 48));
                v3 ^= v2;
            }
            v0 ^= m;
        } else {
            v2 ^= m;
            for (i = 0; i < ctx->crounds; ++i) {
                v2 += v3;
                v3 = (uint64_t)(((v3) << 17) | ((v3) >> 47));
                v3 ^= v2;
                v0 += v1;
                v1 = (uint64_t)(((v1) << 13) | ((v1) >> 51));
                v1 ^= v0;
            }
            v1 ^= m;
        }
    }
}
