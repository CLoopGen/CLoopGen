#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *scantable;
uint32_t *qmul;
int level[16];
int total_coeff;
int i;

void init_vars() {
    const size_t block_size = 1024 * 512; // ~1MB of int16_t data
    const size_t scantable_size = 1024 * 512; // Match size to avoid out-of-bounds
    const size_t qmul_size = scantable_size;

    block = aligned_alloc(16, block_size * sizeof(int16_t));
    scantable = aligned_alloc(16, scantable_size * sizeof(uint8_t));
    qmul = aligned_alloc(16, qmul_size * sizeof(uint32_t));

    for (size_t idx = 0; idx < block_size; idx++) {
        ((int16_t*)block)[idx] = 0;
    }
    for (size_t idx = 0; idx < scantable_size; idx++) {
        scantable[idx] = rand() % block_size;
    }
    for (size_t idx = 0; idx < qmul_size; idx++) {
        qmul[idx] = rand();
    }
    for (int idx = 0; idx < 16; idx++) {
        level[idx] = rand() % 1000;
    }

    total_coeff = 16;
    i = 0;
}