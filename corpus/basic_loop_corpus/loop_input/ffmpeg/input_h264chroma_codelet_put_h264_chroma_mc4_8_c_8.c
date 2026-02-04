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

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    A = 42;
    h = DATA_SIZE / 4;
    stride = 4;

    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }

    dst = dst_buffer;
    src = src_buffer;
}