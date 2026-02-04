#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *scantable;
int level[16];
int total_coeff;
int i;

void init_vars() {
    const size_t block_size = 16 * 1024 * 1024 / sizeof(int16_t);
    block = aligned_alloc(32, block_size * sizeof(int16_t));
    for (size_t idx = 0; idx < block_size; idx++) {
        block[idx] = 0;
    }

    scantable = malloc((total_coeff + 256) * sizeof(uint8_t));
    if (!scantable) exit(1);
    for (int idx = 0; idx < total_coeff + 256; idx++) {
        scantable[idx] = rand() % block_size;
    }

    for (int idx = 0; idx < 16; idx++) {
        level[idx] = rand() % 1000;
    }

    total_coeff = 16;
    i = 0;
}