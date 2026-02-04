#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int width;
int height;
uint8_t prev;
int i;
int j;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 4096;
    height = (DATA_SIZE + width - 1) / width;
    stride = width;
    
    src_buffer = (uint8_t*)aligned_alloc(32, height * stride * sizeof(uint8_t));
    dst_buffer = (uint8_t*)aligned_alloc(32, height * width * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < height * stride; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    src = src_buffer + stride; // Start from second row
    dst = dst_buffer;
    prev = 0;
}