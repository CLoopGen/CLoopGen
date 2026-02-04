#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

static int16_t *src_data;
static int16_t *dst_data;

int16_t *src;
int16_t *dst;

#define DATA_SIZE (64 * 1024 * 1024) // ~128MB of total data to target ~0.01s runtime

void init_vars() {
    src_data = (int16_t*)aligned_alloc(32, DATA_SIZE);
    dst_data = (int16_t*)aligned_alloc(32, DATA_SIZE);

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); ++idx) {
        src_data[idx] = (int16_t)(idx % 512 - 256);
    }

    src = src_data;
    dst = dst_data;

    i = 0;
    t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = 0;
}