#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_wrap;
uint8_t *src;
int src_wrap;
int width;
int height;
int w;
uint8_t *s1;
uint8_t *s2;
uint8_t *s3;
uint8_t *s4;
uint8_t *d;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Set dimensions to achieve ~0.01 sec runtime on modern CPU
    // Empirical testing suggests 64x64 blocks with 64 rows gives good timing
    width = 64;
    height = 64;
    src_wrap = width + 4;  // guard against over-read, align for cache
    dst_wrap = width;

    size_t src_size = (height + 3) * src_wrap;  // 4-row sliding window
    size_t dst_size = height * dst_wrap;

    // Allocate buffers with padding to prevent out-of-bounds access
    src_buffer = (uint8_t*)calloc(1, src_size);
    dst_buffer = (uint8_t*)calloc(1, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with non-zero pattern for better testing
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i % 251);
    }

    // Initialize pointers
    src = src_buffer;
    dst = dst_buffer;
}