#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t dst_stride;
int32_t i;

static uint8_t *dst_buffer;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB
    dst_buffer = (uint8_t *)aligned_alloc(64, data_size);
    if (!dst_buffer) {
        exit(1);
    }

    dst = dst_buffer;
    dst_stride = 1024;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
}