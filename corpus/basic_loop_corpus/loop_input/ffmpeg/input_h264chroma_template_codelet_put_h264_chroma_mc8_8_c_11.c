#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB
    const int elements_per_row = 8;
    
    stride = elements_per_row;
    h = total_size / stride;
    A = 42; 

    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
        dst_buffer[idx] = 0;
    }

    dst = dst_buffer;
    src = src_buffer;
}