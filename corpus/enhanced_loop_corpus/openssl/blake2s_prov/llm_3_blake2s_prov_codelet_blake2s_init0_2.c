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
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    int indices[8] = {2, 5, 1, 7, 0, 4, 6, 3}; // Arbitrary permutation of indices
    for (i = 0; i < 8; ++i) {
        int idx = indices[i];
        S->h[idx] = blake2s_IV[idx];
    }
}
