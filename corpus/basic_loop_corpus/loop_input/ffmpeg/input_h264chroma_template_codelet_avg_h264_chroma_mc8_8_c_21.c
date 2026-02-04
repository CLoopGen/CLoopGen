#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec target)

ptrdiff_t stride = 128;
int h = 512;

uint8_t *dst;
uint8_t *src;

int A = 15;
int B = 26;
int C = 37;
int D = 48;

int i;

static uint8_t data_pool_src[DATA_SIZE];
static uint8_t data_pool_dst[DATA_SIZE];

void init_vars() {
    dst = data_pool_dst;
    src = data_pool_src;

    // Ensure that src and dst have valid memory within bounds for the loop
    // Each iteration accesses up to src[stride + 8], so we need at least (h-1)*stride + 9 bytes
    size_t required_size = (h - 1) * stride + 9;
    if (required_size > DATA_SIZE) {
        // Adjust h to fit within allocated data
        h = (DATA_SIZE - 9) / stride;
        if (h <= 0) h = 1;
    }

    // Initialize source data with non-zero values for meaningful computation
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        data_pool_src[idx] = (uint8_t)(idx % 251);
        data_pool_dst[idx] = (uint8_t)((idx + 41) % 251);
    }
}