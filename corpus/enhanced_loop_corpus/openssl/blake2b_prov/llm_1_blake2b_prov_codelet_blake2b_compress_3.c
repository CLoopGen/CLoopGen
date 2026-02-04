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

extern BLAKE2B_CTX *S;
extern uint64_t v[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        v[i] = S->h[i];
    }
    for (i = 4; i < 8; ++i) {
        v[i] = S->h[i];
    }
}
