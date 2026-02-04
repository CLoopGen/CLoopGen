#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t S[4][4];
uint32_t T[64];
uint32_t ABCD[4];
uint8_t *src;
int nblocks;
int n;
uint32_t *X;
uint32_t a;
uint32_t b;
uint32_t c;
uint32_t d;
uint32_t t;

void init_vars() {
    // Initialize S with non-zero values to avoid trivial computation
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            S[i][j] = (i * 4 + j) % 31; // shift rotation values, kept under 32
        }
    }

    // Initialize T with pseudo-random constants
    for (int i = 0; i < 64; i++) {
        T[i] = 0x36197a5bU ^ (i * 0x6d4dU);
    }

    // Initialize ABCD with initial hash values (similar to MD5-style)
    ABCD[0] = 0x67452301U;
    ABCD[1] = 0xefcdab89U;
    ABCD[2] = 0x98badcfeU;
    ABCD[3] = 0x10325476U;

    // Allocate approximately 16 MB of source data to ensure loop runs ~0.01s
    size_t total_size = 16 << 20; // 16 MiB
    src = (uint8_t*)aligned_alloc(16, total_size);
    if (!src) abort();
    memset(src, 0, total_size);

    // Fill with non-zero data to prevent compiler from optimizing out
    for (size_t i = 0; i < total_size; i++) {
        src[i] = (uint8_t)(i ^ (i >> 8) ^ (i >> 16) ^ (i >> 24));
    }

    // Each block uses 16 uint32_t = 64 bytes
    int bytes_per_block = 16 * sizeof(uint32_t);
    nblocks = (int)(total_size / bytes_per_block);

    // Ensure we don't exceed allocated bounds
    if (nblocks > (int)(total_size / bytes_per_block)) {
        nblocks = (int)(total_size / bytes_per_block);
    }

    // Initialize working variables
    a = b = c = d = 0;
    t = 0;
    X = NULL;
    n = 0;
}