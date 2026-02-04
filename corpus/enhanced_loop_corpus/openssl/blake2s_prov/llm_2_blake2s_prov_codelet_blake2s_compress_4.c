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

extern BLAKE2S_CTX *S;
extern uint32_t v[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step of 2, unrolled partial iteration
    for (i = 0; i < 8; i += 2) {
        size_t idx1 = i;
        size_t idx2 = i + 1;
        S->h[idx1] = v[idx1] ^= v[idx1 + 8] ^ S->h[idx1];
        if (idx2 < 8) {
            S->h[idx2] = v[idx2] ^= v[idx2 + 8] ^ S->h[idx2];
        }
    }
}
