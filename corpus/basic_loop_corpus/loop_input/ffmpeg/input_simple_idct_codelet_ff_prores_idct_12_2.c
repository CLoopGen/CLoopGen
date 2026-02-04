#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static int16_t *block_data;
static int16_t *qmat_data;
int i;

int16_t *block;
int16_t *qmat;

void init_vars() {
    block_data = (int16_t *)aligned_alloc(32, DATA_SIZE);
    qmat_data = (int16_t *)aligned_alloc(32, DATA_SIZE);

    if (!block_data || !qmat_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); idx++) {
        block_data[idx] = (int16_t)(idx % 512 - 256);
        qmat_data[idx] = (int16_t)(idx % 256 - 128);
    }

    block = block_data;
    qmat = qmat_data;
}