#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int h = 100000;
int pad = 10;
int i;

static uint16_t *src_data;
static int32_t *tmp_data;
uint16_t *src;
int32_t *tmp;
int tmpStride = 1;
int srcStride = 4;

void init_vars() {
    const size_t total_src_size = (h + 5) * srcStride + 5;
    const size_t total_tmp_size = (h + 5) * tmpStride;

    src_data = aligned_alloc(32, total_src_size * sizeof(uint16_t));
    tmp_data = aligned_alloc(32, total_tmp_size * sizeof(int32_t));

    if (!src_data || !tmp_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_src_size; idx++) {
        src_data[idx] = (uint16_t)(idx % 1024);
    }

    for (size_t idx = 0; idx < total_tmp_size; idx++) {
        tmp_data[idx] = 0;
    }

    src = src_data + 2;
    tmp = tmp_data;
}