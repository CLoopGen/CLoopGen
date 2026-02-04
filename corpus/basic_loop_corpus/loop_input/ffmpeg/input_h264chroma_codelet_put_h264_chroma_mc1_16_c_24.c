#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A = 17;
int B = 37;
int C = 19;
int D = 41;
int i;

static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64MB of source data
    const size_t element_size = sizeof(uint16_t);
    const int width = 512; // Choose a reasonable width

    h = total_size / (width * element_size);
    if (h < 1) h = 1;
    stride = width;

    size_t buffer_size = (h + 1) * stride + 2; // Extra padding for safe access to src[stride+1]

    dst_buffer = aligned_alloc(32, buffer_size * sizeof(uint16_t));
    src_buffer = aligned_alloc(32, buffer_size * sizeof(uint16_t));

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(dst_buffer, 0, buffer_size * sizeof(uint16_t));
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = rand() & 0xFFFF;
    }

    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
    free(src_buffer);
}