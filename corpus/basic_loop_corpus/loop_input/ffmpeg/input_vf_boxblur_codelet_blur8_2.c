#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
uint8_t *src;
int src_step;
int radius;
int inv;
int x;
int sum;

static uint8_t *src_storage;
static uint8_t *dst_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    src_storage = (uint8_t*)aligned_alloc(32, data_size);
    dst_storage = (uint8_t*)aligned_alloc(32, data_size);

    if (!src_storage || !dst_storage) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_storage[i] = rand() & 0xFF;
        dst_storage[i] = 0;
    }

    src = src_storage;
    dst = dst_storage;

    src_step = 1;
    dst_step = 1;

    radius = (int)((data_size / 2) - 1); // ensures (radius + x) * src_step < data_size when x <= radius
    inv = 0x1000; // arbitrary non-zero scaling factor for fixed-point arithmetic
    x = 0;
    sum = 0;
}