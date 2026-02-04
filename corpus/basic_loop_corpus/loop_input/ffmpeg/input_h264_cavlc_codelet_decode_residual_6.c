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
    const size_t block_size = 1 << 17;  // 128K elements of int16_t (256KB)
    const size_t scantable_size = 1 << 16;  // 64K elements of uint8_t (64KB)
    const size_t qmul_size = 1 << 16;   // 64K elements of uint32_t (256KB)

    block = aligned_alloc(16, block_size * sizeof(int16_t));
    scantable = aligned_alloc(16, scantable_size * sizeof(uint8_t));
    qmul = aligned_alloc(16, qmul_size * sizeof(uint32_t));

    for (size_t idx = 0; idx < block_size; idx++) {
        block[idx] = (int16_t)(idx & 0x3FF);
    }
    for (size_t idx = 0; idx < scantable_size; idx++) {
        scantable[idx] = (uint8_t)((idx * 7) % 64);
    }
    for (size_t idx = 0; idx < qmul_size; idx++) {
        qmul[idx] = (uint32_t)(idx * 1103515245 + 12345);
    }

    for (int idx = 0; idx < 16; idx++) {
        level[idx] = (idx + 1) * 10;
    }

    total_coeff = 16;
    i = 0;

    // Ensure that during the loop, scantable-- doesn't go out of bounds
    // We start scantable pointer at offset + total_coeff so that after decrementing total_coeff times,
    // it remains within [0, scantable_size)
    if (total_coeff <= (int)scantable_size) {
        scantable += total_coeff;
    } else {
        total_coeff = (int)scantable_size;
    }
}