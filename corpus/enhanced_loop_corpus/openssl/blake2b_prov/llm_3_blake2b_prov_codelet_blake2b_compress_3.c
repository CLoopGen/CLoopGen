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
    // Variant 2: Indirect memory access using a lookup table for index permutation
    // Simulates non-sequential access pattern, e.g., reversing the order of access
    const int index_map[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order
    for (i = 0; i < 8; ++i) {
        int mapped_idx = index_map[i];
        v[mapped_idx] = S->h[mapped_idx];
    }
}
