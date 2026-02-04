#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for sufficient runtime (~0.01 sec)

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w1;
int w2;
ptrdiff_t stride;
int i;
int j;

static uint8_t *buffer1;
static uint8_t *buffer2;
static uint8_t *buffer_dst;

void init_vars() {
    // Set weights
    w1 = 13;
    w2 = 19;

    // Each row is 16 bytes, we need at least 16 rows to avoid out-of-bounds
    stride = 16;

    // Allocate buffers: we need at least 16 rows of 16 bytes for each array
    buffer1 = aligned_alloc(32, DATA_SIZE);
    buffer2 = aligned_alloc(32, DATA_SIZE);
    buffer_dst = aligned_alloc(32, DATA_SIZE);

    if (!buffer1 || !buffer2 || !buffer_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with non-zero values for meaningful computation
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        buffer1[idx] = (uint8_t)(idx % 251);
        buffer2[idx] = (uint8_t)((idx * 3) % 251);
    }

    // Initialize dst to zero
    memset(buffer_dst, 0, DATA_SIZE);

    // Set the external pointers to the start of buffers
    src1 = buffer1;
    src2 = buffer2;
    dst = buffer_dst;
}