#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t *iv2p;
aes_block_t *outp;

void init_vars() {
    const size_t num_blocks = 8192; // ~128KB of data: 8192 blocks * 16 bytes = 131072 bytes

    iv2p = (aes_block_t*)aligned_alloc(_Alignof(aes_block_t), num_blocks * sizeof(aes_block_t));
    outp = (aes_block_t*)aligned_alloc(_Alignof(aes_block_t), num_blocks * sizeof(aes_block_t));

    for (size_t i = 0; i < num_blocks; ++i) {
        iv2p[i].data[0] = i;
        iv2p[i].data[1] = i + 1;
        outp[i].data[0] = i + 2;
        outp[i].data[1] = i + 3;
    }

    n = 0;
}