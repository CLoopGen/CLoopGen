#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int y;
int size;
uint16_t *src;
uint16_t *left;
int dc;

#define DATA_SIZE (64 * 1024 * 1024)  // ~128MB of total data (adjustable)

static uint16_t src_buffer[DATA_SIZE];
static uint16_t left_buffer[DATA_SIZE];

void init_vars() {
    // Set reasonable problem size and stride
    size = 16384;  // Must be less than DATA_SIZE to avoid OOB access
    stride = 4096;
    dc = 1234;

    // Ensure that for y in [1, size-1], the index (0 + stride * y) is within bounds
    // Max index: stride * (size - 1) < DATA_SIZE  =>  size <= DATA_SIZE / stride + 1
    if (stride * (size - 1) >= DATA_SIZE) {
        size = (DATA_SIZE - 1) / stride + 1;
    }

    src = src_buffer;
    left = left_buffer;

    // Initialize left array to avoid undefined behavior
    for (int i = 0; i < size; i++) {
        left[i] = i * 7 + 3;
    }

    // Initialize dc and other scalars
    dc = 512;

    // Initialize y to a safe state (will be overwritten by loop)
    y = 0;
}