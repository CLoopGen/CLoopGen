#include <stdio.h>

#include <inttypes.h>

struct blake2s_ctx_st {
    uint32_t h[8];
    uint32_t t[2];
    uint32_t f[2];
    uint8_t buf[64];
    size_t buflen;
    size_t outlen;
};


typedef struct blake2s_ctx_st BLAKE2S_CTX;

extern  uint32_t blake2s_IV[8];
extern BLAKE2S_CTX *S;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    S->h[0] = blake2s_IV[0];
    for (i = 1; i < 8; ++i) {
        S->h[i] = blake2s_IV[i] + S->h[i-1] - blake2s_IV[i-1];
    }
}
