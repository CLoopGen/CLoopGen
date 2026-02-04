#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *permutation;
uint8_t *scantable;
int last;
int i;
int16_t temp[64];

void init_vars() {
    const size_t block_size = 256 * 1024 * sizeof(int16_t);
    block = aligned_alloc(32, block_size);
    for (size_t idx = 0; idx < block_size / sizeof(int16_t); ++idx) {
        block[idx] = (int16_t)(idx % 32768);
    }

    permutation = aligned_alloc(32, 256 * sizeof(uint8_t));
    for (int idx = 0; idx < 256; ++idx) {
        permutation[idx] = (uint8_t)((idx * 167) % 256);
    }

    scantable = aligned_alloc(32, 64 * sizeof(uint8_t));
    for (int idx = 0; idx < 64; ++idx) {
        scantable[idx] = (uint8_t)((63 - idx) * 4 % 64);
    }

    for (int idx = 0; idx < 64; ++idx) {
        temp[idx] = (int16_t)(32767 - idx * 512);
    }

    last = 63;
}