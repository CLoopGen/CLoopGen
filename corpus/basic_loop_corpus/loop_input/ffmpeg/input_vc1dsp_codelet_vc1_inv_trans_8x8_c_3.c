#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int i;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

static int16_t *src_buffer;
static int16_t *dst_buffer;

int16_t *src;
int16_t *dst;

void init_vars() {
    size_t data_size = 256 * 1024 * sizeof(int16_t); // 512KB of data (256K elements)
    src_buffer = (int16_t *)aligned_alloc(32, data_size);
    dst_buffer = (int16_t *)aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < 256 * 1024; idx++) {
        src_buffer[idx] = (int16_t)(idx % 512 - 256); // populate with small oscillating values
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}