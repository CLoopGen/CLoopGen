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
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    const int index_map[8] = {7, 0, 5, 2, 3, 4, 1, 6}; // Arbitrary permutation of indices
    for (i = 0; i < 8; ++i) {
        int idx = index_map[i];
        S->h[idx] = v[idx] ^= v[idx + 8] ^ S->h[idx];
    }
}
