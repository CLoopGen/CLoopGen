#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01s on modern CPU)

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 26;
    C = 37;
    D = 48;

    // Set height to ensure we don't exceed buffer bounds in the loop
    h = 800;

    // Stride chosen to allow safe access with offset +9 in inner loop
    stride = 1024; // > 9 to prevent overflow in any row

    // Allocate large buffers with padding for safety
    size_t total_size = (h + 2) * stride + 16; // Add guard space
    if (total_size < DATA_SIZE) {
        total_size = DATA_SIZE;
    }

    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);
    src_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Clear allocated memory
    memset(dst_buffer, 0, total_size);
    memset(src_buffer, 0, total_size);

    // Initialize src with non-zero values for meaningful computation
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(rand() % 256);
    }

    // Point dst and src to valid region within buffers
    // Ensure that even last iteration doesn't go out of bounds
    ptrdiff_t offset = 0;
    dst = dst_buffer + offset;
    src = src_buffer + offset;
}