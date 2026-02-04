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



void loop() {
    // Variant 1: Strided memory access with step size 2, unrolled to maintain correctness
    // We traverse the h array in two passes: first even indices, then odd indices.
    int idx;
    for (i = 0; i < 4; ++i) {
        idx = i * 2;
        v[idx] = S->h[idx];
    }
    for (i = 0; i < 4; ++i) {
        idx = i * 2 + 1;
        v[idx] = S->h[idx];
    }
}
