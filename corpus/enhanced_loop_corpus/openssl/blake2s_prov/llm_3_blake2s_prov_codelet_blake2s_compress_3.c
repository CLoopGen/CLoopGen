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
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    const size_t indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Even indices first, then odd
    size_t j;
    for (j = 0; j < 8; ++j) {
        v[j] = S->h[indices[j]];
    }
}
