#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *block;
int i;
int temp[64];

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    const int num_blocks = data_size / (8 * sizeof(int32_t));

    // Allocate block to ensure 8*8*i accesses stay in bounds for i from 0 to 7
    // We need at least 8*8 = 64 elements for the maximum index 8*7+7 = 63
    block = aligned_alloc(32, num_blocks * 64 * sizeof(int32_t));
    if (!block) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize temp with non-zero values for meaningful computation
    for (int j = 0; j < 64; j++) {
        temp[j] = (j + 1) * 31;
    }

    // Seed and initialize block data to avoid undefined behavior
    srand((unsigned int)time(NULL));
    for (int j = 0; j < num_blocks * 64; j++) {
        block[j] = rand() % 256;
    }
}