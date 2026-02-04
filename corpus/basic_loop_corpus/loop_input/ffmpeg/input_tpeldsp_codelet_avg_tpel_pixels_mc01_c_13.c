#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20))

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 4096;
    height = (TOTAL_ELEMENTS / width);
    while ((uint64_t)width * height > TOTAL_ELEMENTS) {
        height--;
    }
    stride = width + 16;
    uint64_t buffer_size = (uint64_t)stride * height;

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (uint64_t k = 0; k < buffer_size; k++) {
        src_buffer[k] = rand() & 0xFF;
        dst_buffer[k] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}