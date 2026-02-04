#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *src;
int src_step = 1;
int radius;
int x;
int sum;

static uint16_t *src_buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    src_buffer = (uint16_t*)aligned_alloc(32, data_size);
    if (!src_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(uint16_t); i++) {
        src_buffer[i] = (uint16_t)(i & 0xFFFF);
    }

    src = src_buffer;
    radius = (int)(data_size / sizeof(uint16_t) / src_step);
    sum = 0;
}