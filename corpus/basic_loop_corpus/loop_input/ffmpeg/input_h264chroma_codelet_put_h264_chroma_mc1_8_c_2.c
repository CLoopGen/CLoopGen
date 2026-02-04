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
    A = 123;
    h = 2097152;  // Process ~2M elements to target ~0.01 sec runtime
    stride = 1;

    size_t buffer_size = (size_t)h * (size_t)stride;
    dst_buffer = aligned_alloc(32, buffer_size);
    src_buffer = aligned_alloc(32, buffer_size);

    if (!dst_buffer || !src_buffer) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
        dst_buffer[idx] = 0;
    }

    dst = dst_buffer;
    src = src_buffer;
}