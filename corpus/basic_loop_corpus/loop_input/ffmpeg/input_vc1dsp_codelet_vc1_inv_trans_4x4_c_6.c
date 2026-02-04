#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int t1;
int t2;
int t3;
int t4;

static int16_t *src_data;
static int16_t *dst_data;

int16_t *src;
int16_t *dst;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB of data (adjustable)
    src_data = aligned_alloc(32, total_size);
    dst_data = aligned_alloc(32, total_size);

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(int16_t); idx++) {
        src_data[idx] = rand() % 100 - 50;
        dst_data[idx] = 0;
    }

    src = src_data;
    dst = dst_data;
}