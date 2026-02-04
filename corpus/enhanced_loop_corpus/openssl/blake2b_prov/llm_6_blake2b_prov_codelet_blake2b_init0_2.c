#include <stdio.h>

#include <inttypes.h>

struct blake2b_ctx_st {
    uint64_t h[8];
    uint64_t t[2];
    uint64_t f[2];
    uint8_t buf[128];
    size_t buflen;
    size_t outlen;
};


typedef struct blake2b_ctx_st BLAKE2B_CTX;

extern  uint64_t blake2b_IV[8];
extern BLAKE2B_CTX *S;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_h[8];
    for (i = 0; i < 8; ++i) {
        temp_h[i] = blake2b_IV[i];
    }
    for (i = 0; i < 8; ++i) {
        S->h[i] = temp_h[i];
    }
}
