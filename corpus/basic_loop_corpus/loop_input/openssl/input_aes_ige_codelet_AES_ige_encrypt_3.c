#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t tmp2;
aes_block_t iv2;

void init_vars() {
    // Initialize the data arrays to non-zero values for meaningful operations
    for (int i = 0; i < 2; ++i) {
        tmp2.data[i] = 0x12345678ABCDEF00ULL + i;
        iv2.data[i] = 0xFEDCBA9876543210ULL + i;
    }
}