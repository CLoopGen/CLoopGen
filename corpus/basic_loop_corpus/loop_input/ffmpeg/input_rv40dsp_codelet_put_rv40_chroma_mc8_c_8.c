#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int i;
int bias;
int E;
ptrdiff_t step;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int width = 8;
    h = (DATA_SIZE / width) / 2; // Adjust so total data is about 128MB
    if (h < 1) h = 1;

    stride = width * sizeof(uint8_t);
    step = width;
    
    A = 17;
    E = 31;
    bias = 42;

    // Allocate buffers with extra padding to avoid out-of-bounds access
    size_t buffer_size = (h * stride) + (step + width);
    
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with non-zero values for meaningful computation
    srand((unsigned int)time(NULL));
    for (int j = 0; j < (int)(buffer_size); j++) {
        src_buffer[j] = rand() & 0xFF;
    }
    memset(dst_buffer, 0, buffer_size);

    // Initialize pointers
    src = src_buffer;
    dst = dst_buffer;
}

// Cleanup function to free allocated memory (not called in loop but good practice)
void cleanup_vars() {
    if (src_buffer) free(src_buffer);
    if (dst_buffer) free(dst_buffer);
}