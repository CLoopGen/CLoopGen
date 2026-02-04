#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t temp_matrix[64];
uint8_t *old_perm;
uint8_t *new_perm;
uint16_t *matrix;
int i;

void init_vars() {
    old_perm = (uint8_t *)aligned_alloc(64, 64 * sizeof(uint8_t));
    new_perm = (uint8_t *)aligned_alloc(64, 64 * sizeof(uint8_t));
    matrix = (uint16_t *)aligned_alloc(64, 131072 * sizeof(uint16_t)); // ~256KB to target 0.01s runtime

    for (int idx = 0; idx < 64; idx++) {
        old_perm[idx] = idx;
        new_perm[idx] = idx;
    }

    for (int idx = 0; idx < 64; idx++) {
        temp_matrix[idx] = (uint16_t)(idx * 2);
    }

    for (int idx = 0; idx < 131072; idx++) {
        matrix[idx] = 0;
    }
}