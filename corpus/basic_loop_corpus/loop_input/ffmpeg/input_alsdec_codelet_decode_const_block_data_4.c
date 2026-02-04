#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int smp;
int32_t val;
int32_t *dst;

static int32_t *dst_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for predictable loop duration
    dst_buffer = (int32_t *)aligned_alloc(32, data_size);
    if (!dst_buffer) {
        exit(1);
    }

    dst = dst_buffer;
    smp = data_size / sizeof(int32_t);
    val = 0xdeadbeef;
}