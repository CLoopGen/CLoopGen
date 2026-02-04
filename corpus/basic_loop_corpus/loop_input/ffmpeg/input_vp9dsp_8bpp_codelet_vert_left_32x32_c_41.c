#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *top;
int i;
uint8_t ve[31];
uint8_t vo[31];

static uint8_t *data_pool;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    data_pool = (uint8_t *)malloc(data_size);
    if (!data_pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with pseudo-random data based on time and pattern
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < data_size; ++idx) {
        data_pool[idx] = (uint8_t)((rand() >> 8) & 0xFF);
    }

    top = data_pool;

    // Ensure that loop accesses within bounds: i < 32 - 2 => i < 30, so we need at least 32 elements in top
    // But our data_pool is much larger (1MB), so it's safe.
    // Also initialize ve and vo to zero to avoid undefined behavior if accessed before written
    memset(ve, 0, sizeof(ve));
    memset(vo, 0, sizeof(vo));
}