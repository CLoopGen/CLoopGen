#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 42; // arbitrary non-zero value for computation
    h = (DATA_SIZE / 4) / sizeof(uint8_t); // each iteration accesses 4 bytes, adjust h accordingly
    stride = 4; // each iteration processes 4 consecutive bytes

    // Allocate buffers with extra padding to prevent overflow
    dst_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    src_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        dst_buffer[idx] = (uint8_t)(idx % 256);
        src_buffer[idx] = (uint8_t)((2 * idx + 17) % 256);
    }

    // Set pointers to start of buffers
    dst = dst_buffer;
    src = src_buffer;

    // Ensure h is consistent with allocated size and stride
    h = (DATA_SIZE / stride) / 4; // because each loop does 4 unrolled accesses
}