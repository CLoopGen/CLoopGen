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
    total_coeff = 16;
    i = 0;

    for (int idx = 0; idx < 16; idx++) {
        level[idx] = (int)(idx * 100);
    }

    block = aligned_alloc(16, 32 * sizeof(int16_t));
    scantable = malloc(total_coeff * sizeof(uint8_t));

    if (!block || !scantable) {
        exit(1);
    }

    for (int idx = 0; idx < total_coeff; idx++) {
        scantable[idx] = (uint8_t)(total_coeff - 1 - idx);
    }

    for (int idx = 0; idx < 32; idx++) {
        block[idx] = (int16_t)0;
    }
}