#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int element_size = 2; 
    const int src_row_width = 2 * width;
    const int dst_row_width = 3 * width;

    width = 1024; 
    src_stride = width * 2;
    dst_stride = width * 3;

    size_t src_size = (size_t)src_stride * 2;
    size_t dst_size = (size_t)dst_stride * 2;

    src_buffer = aligned_alloc(32, src_size + 32);
    dst_buffer = aligned_alloc(32, dst_size + 32);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    i = 0;
}